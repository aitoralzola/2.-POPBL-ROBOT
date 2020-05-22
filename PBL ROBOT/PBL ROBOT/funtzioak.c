#define _CRT_SECURE_NO_WARNINGS
#include "sdlHasieratu.h"
#include "irudiak.h"
#include "kontrolak.h"
#include "funtzioak.h"

POSIZIOA saguPos;

int V, cost[20][20], src = 0, end;
int distance[20], parent[20], visited[20] = { 0 };

int hasiPrograma() {
    int itxi = 0, menu, ebentua;

    menu = irudiaSortu(MENU);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);

    ebentua = ebentuaJasoGertatuBada();
    if (ebentua == TECLA_0) {
        irudiaKendu(menu);
        pantailaGarbitu();
        barrua();
    }
    if (ebentua == TECLA_1) {
        irudiaKendu(menu);
        pantailaGarbitu();
        terraza();
    }
    if (ebentua == TECLA_ESCAPE) itxi = -1;

    return itxi;
}

void barrua() {
    int itxi, barrua, robot;
    char* str = { "matriz_barrualdea.txt" };

    barrua = irudiaSortu(BARRUALDEA);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
    robot = irudiaSortu(ROBOT);
    irudiaMugitu(robot, 664, 80);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);

    V = 12;
    matrizeaOsatu(str);
    dijkstra();
    end = mahaiaItzuliBarruan();
    pantailaratu();

    do {
        itxi = ebentuaJasoGertatuBada();
    } while (itxi != TECLA_ESCAPE);
    if (itxi == TECLA_ESCAPE) {
        irudiaKendu(barrua);
        irudiaKendu(robot);
        pantailaGarbitu();
    }
}

void terraza() {
    int itxi, terraza, robot;
    char* str = { "matriz_terraza.txt" };

    terraza = irudiaSortu(TERRAZA);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
    robot = irudiaSortu(ROBOT);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);

    V = 7;
    matrizeaOsatu(str);
    init();
    dijkstra();

    do {
        itxi = ebentuaJasoGertatuBada();
    } while (itxi != TECLA_ESCAPE);
    if (itxi == TECLA_ESCAPE) {
        irudiaKendu(terraza);
        irudiaKendu(robot);
        pantailaGarbitu();
    }
}

void matrizeaOsatu(char* str) {
    FILE* fp;

    fp = fopen(str, "r");
    if (fp != NULL) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                fscanf(fp, "%d", &cost[i][j]);
                if (cost[i][j] == 0)
                    cost[i][j] = 999;
            }
        }
    }
}

int mahaiaItzuliBarruan() {
    
    int i, mahai = 0;
    
    do {
        i = ebentuaJasoGertatuBada();
        saguPos = saguarenPosizioa();
    } while (i != SAGU_BOTOIA_EZKERRA);

    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 470) && (saguPos.x < 535) && (saguPos.y > 23) && (saguPos.y < 88)) mahai = 1;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 344) && (saguPos.y > 23) && (saguPos.y < 88)) mahai = 2;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 408) && (saguPos.y > 215) && (saguPos.y < 280)) mahai = 3;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 345) && (saguPos.y > 344) && (saguPos.y < 407)) mahai = 4;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 345) && (saguPos.y > 472) && (saguPos.y < 536)) mahai = 5;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 408) && (saguPos.x < 536) && (saguPos.y > 472) && (saguPos.y < 536)) mahai = 6;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 666) && (saguPos.x < 730) && (saguPos.y > 408) && (saguPos.y < 472)) mahai = 7;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 666) && (saguPos.x < 730) && (saguPos.y > 218) && (saguPos.y < 280)) mahai = 8;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 536) && (saguPos.x < 664) && (saguPos.y > 344) && (saguPos.y < 408)) mahai = 9;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 408) && (saguPos.x < 472) && (saguPos.y > 280) && (saguPos.y < 344)) mahai = 10;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 472) && (saguPos.x < 536) && (saguPos.y > 152) && (saguPos.y < 216)) mahai = 11;

    return mahai;
}

int mahaiaItzuliTerraza() {
    int i, mahai = 0;

    do {
        i = ebentuaJasoGertatuBada();
        saguPos = saguarenPosizioa();
    } while (i != SAGU_BOTOIA_EZKERRA);

    return mahai;
}

int getNearest() {
    int minValue = INF;
    int minNode = 0;

    for (int i = 0; i < V; i++) {
        if (distance[i] < minValue && visited[i] == 0) {
            minValue = distance[i];
            minNode = i;
        }
    }
    return minNode;
}

void dijkstra() {
    int nearest;
    
    init();
    for (int i = 0; i < V; i++) {
        nearest = getNearest();
        visited[nearest] = 1;

        for (int adj = 0; adj < V; adj++) {
            if (cost[nearest][adj] != INF && distance[adj] > distance[nearest] + cost[nearest][adj]) {
                distance[adj] = distance[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

void init() {

    for (int i = 0; i < V; i++) {
        distance[i] = INF;
        parent[i] = 1;
    }
    distance[src] = 0;
}

void pantailaratu() {
    printf("Node:\t\tCost:\t\tPath:");

    printf("\n%d\t\t%d\t\t ", end, distance[end]);
    printf("%d", end);
    int parnode = parent[end];
    while (parnode != src) {
        printf(" <- %d ", parnode);
        parnode = parent[parnode];
    }
    printf("\n");
}

POSIZIOA saguarenPosizioa() { return saguPos; }