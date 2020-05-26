#define _CRT_SECURE_NO_WARNINGS
#include "sdlHasieratu.h"
#include "irudiak.h"
#include "kontrolak.h"
#include "funtzioak.h"

POSIZIOA saguPos;

int V, **cost, src = 0, end;
int *distance, *parent, *visited;

int hasiPrograma() {
    int itxi = 0, menu, ebentua;
    POSIZIOA saguPos;

    menu = irudiaSortu(MENU);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);

    do {
        ebentua = ebentuaJasoGertatuBada();
        saguPos = saguarenPosizioa();
    } while (ebentua != SAGU_BOTOIA_EZKERRA);

    if (ebentua == SAGU_BOTOIA_EZKERRA && saguPos.x > 250 && saguPos.x < 455 && saguPos.y>170 && saguPos.y < 195) {
        irudiaKendu(menu);
        pantailaGarbitu();
        barrua();
    }
    if (ebentua == SAGU_BOTOIA_EZKERRA && saguPos.x > 250 && saguPos.x < 455 && saguPos.y > 195 && saguPos.y < 220) {
        irudiaKendu(menu);
        pantailaGarbitu();
        terraza();
    }
    if (ebentua == SAGU_BOTOIA_EZKERRA && saguPos.x > 250 && saguPos.x < 455 && saguPos.y > 220 && saguPos.y < 245) {
        irudiaKendu(menu);
        pantailaGarbitu();
        itxi = -1;
    }

    return itxi;
}

void barrua() {
    MAHAIAK* burua = NULL, *ptrAux;
    int itxi, fondoa, robot, pertsona;
    char* str = { "matriz_barrualdea.txt" }, * mahaiak = { "mahaiak_barrualdea.txt" };
    V = 12;

    irudiakJarri(&robot, &fondoa);
    matrizeaOsatu(str);
    mahaienPosizioa(&burua, mahaiak);
    dijkstra();
    end = mahaiaItzuliBarruan();
    ptrAux = pertsonaMugitu(burua);
    pertsonaKokatu(&pertsona, ptrAux);
    pantailaratu(burua, &robot, end);
    memoriaGarbitu(&burua);

    do {
        itxi = ebentuaJasoGertatuBada();
    } while (itxi != TECLA_ESCAPE);
    if (itxi == TECLA_ESCAPE) {
        irudiakEzabatu(&pertsona, &fondoa, &robot);
    }
}

void terraza() {
    MAHAIAK* burua = NULL, * ptrAux;
    int itxi, terraza, robot, pertsona;
    char* str = { "matriz_terraza.txt" }, * mahaiak = { "mahaiak_terraza.txt" };
    V = 7;
    
    irudiakJarri(&robot, &terraza);
    matrizeaOsatu(str);
    mahaienPosizioa(&burua, mahaiak);
    dijkstra();
    end = mahaiaItzuliTerraza();
    ptrAux = pertsonaMugitu(burua);
    pertsonaKokatu(&pertsona, ptrAux);
    pantailaratu(burua, &robot, end);
    memoriaGarbitu(&burua);

    do {
        itxi = ebentuaJasoGertatuBada();
    } while (itxi != TECLA_ESCAPE);
    if (itxi == TECLA_ESCAPE) {
        irudiaKendu(terraza);
        irudiaKendu(robot);
        pantailaGarbitu();
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

    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 489) && (saguPos.x < 645) && (saguPos.y > 0) && (saguPos.y < 138)) mahai = 1;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 188) && (saguPos.x < 327) && (saguPos.y > 0) && (saguPos.y < 138)) mahai = 2;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 50) && (saguPos.x < 647) && (saguPos.y > 200) && (saguPos.y < 353)) mahai = 3;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 188) && (saguPos.x < 327) && (saguPos.y > 200) && (saguPos.y < 353)) mahai = 4;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 510) && (saguPos.x < 658) && (saguPos.y > 400) && (saguPos.y < 547)) mahai = 5;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 199) && (saguPos.x < 345) && (saguPos.y > 400) && (saguPos.y < 544)) mahai = 6;

    return mahai;
}

void mahaienPosizioa(MAHAIAK** burua, char* mahaiak) {
    FILE* fp;
    MAHAIAK* ptrAux;

    fp = fopen(mahaiak, "r");
    if (fp != NULL) {
        do {
            ptrAux = (MAHAIAK*)malloc(sizeof(MAHAIAK));
            if (ptrAux != NULL) {
                fscanf(fp, "%d %d", &ptrAux->x, &ptrAux->y);
                ptrAux->ptrHurrengoa = NULL;
                if (*burua == NULL) {
                    *burua = ptrAux;
                }
                else {
                    ptrAux->ptrHurrengoa = *burua;
                    *burua = ptrAux;
                }
            }
        } while (!feof(fp));
    }
}

void memoriaErreserbatu() {
    cost = (int**)malloc(sizeof(int*) * V);
    if (cost != NULL) {
        for (int i = 0; i < V; i++) {
            *(cost + i) = (int*)malloc(sizeof(int) * V);
        }
    }
    visited = (int*)malloc(sizeof(int) * V);
    parent = (int*)malloc(sizeof(int) * V);
    distance = (int*)malloc(sizeof(int) * V);
}

void matrizeaOsatu(char* str) {
    FILE* fp;

    fp = fopen(str, "r");
    if (fp != NULL) {
        memoriaErreserbatu();
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                fscanf(fp, "%d", &cost[i][j]);
                if (cost[i][j] == 0)
                    cost[i][j] = INF;
            }
        }
    }
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
        *(visited + nearest) = 1;

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
        *(visited + i) = 0;
        *(distance + i) = INF;
        *(parent + i) = 1;
    }
    *(distance + src) = 0;
}

void memoriaGarbitu(MAHAIAK** burua) {
    MAHAIAK* ptrAux, *aurrekoa;
    for (int i = 0; i < V; i++) {
        free(cost[i]);
    }
    free(cost);
    free(parent);
    free(visited);
    free(distance);
    ptrAux = *burua;
    while (ptrAux != NULL) {
        aurrekoa = ptrAux;
        ptrAux = ptrAux->ptrHurrengoa;
        free(aurrekoa);
    }
}

MAHAIAK* pertsonaMugitu(MAHAIAK* burua) {
    int kont = V - 1;
    MAHAIAK* ptrAux;
    ptrAux = burua;

    while (kont > end && ptrAux != NULL) {
        ptrAux = ptrAux->ptrHurrengoa;
        kont--;
    }
    return ptrAux;
}

void irudiakJarri(int* robot, int* fondoa) {
    if (V == 12) {
        *fondoa = irudiaSortu(BARRUALDEA);
        *robot = irudiaSortu(ROBOT);
        irudiaMugitu(*robot, 604, -20);
        irudiakMarraztu();
        SDL_RenderPresent(gRenderer);
    }
    else {
        *fondoa = irudiaSortu(TERRAZA);
        *robot = irudiaSortu(ROBOT);
        irudiaMugitu(*robot, 604, -20);
        irudiakMarraztu();
        SDL_RenderPresent(gRenderer);
    }
    
}

void pertsonaKokatu(int* pertsona, MAHAIAK* ptrAux) {
    *pertsona = irudiaSortu(PERTSONA);
    irudiaMugitu(*pertsona, ptrAux->x, ptrAux->y);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
}

void irudiakEzabatu(int* pertsona, int* fondoa, int* errobota) {
    irudiaKendu(*pertsona);
    irudiaKendu(*fondoa);
    irudiaKendu(*errobota);
    pantailaGarbitu();
}

void pantailaratu(MAHAIAK* buruMahai, int* robot, int end) {
    /*int parnode;*/
    MAHAIAK* ptrAuxM;

    if (end != src) {
        pantailaratu(buruMahai, robot, parent[end]);
    }
    ptrAuxM = mahaiaAurkitu(buruMahai, end);
    mugimendua(ptrAuxM, robot);
    /*printf("Node:\t\tCost:\t\tPath:");

    printf("\n%d\t\t%d\t\t ", end, distance[end]);
    printf("%d", end);
    int parnode = parent[end];
    while (parnode != src) {
        printf(" <- %d ", parnode);
        parnode = parent[parnode];
    }
    printf("\n");*/
}

MAHAIAK* mahaiaAurkitu(MAHAIAK* buruMahai, int parnode) {
    MAHAIAK* ptrAux = buruMahai;
    int kont = V - 1;

    while (kont > parnode) {
        ptrAux = ptrAux->ptrHurrengoa;
        kont--;
    }

    return ptrAux;
}

void mugimendua(MAHAIAK* ptrAux, int* robot) {
    static int aurrekoX = 640, aurrekoY = -20;

    POSIZIOA pos;
    pos.x = aurrekoX;
    pos.y = aurrekoY;
    
    if (ptrAux != NULL) {
        while (pos.x != ptrAux->x || pos.y != ptrAux->y) {
            pos = mugitu(pos, ptrAux);
            irudiaMugitu(*robot, pos.x, pos.y);
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
        }
    }
    aurrekoX = pos.x;
    aurrekoY = pos.y;
}

POSIZIOA mugitu(POSIZIOA pos, MAHAIAK* ptrAux) {
    if (pos.x > ptrAux->x) {
        pos.x -= 1;
    }
    if (pos.x < ptrAux->x) {
        pos.x += 1;
    }
    if (pos.y > ptrAux->y) {
        pos.y -= 1;
    }
    if (pos.y < ptrAux->y) {
        pos.y += 1;
    }

    return pos;
}

POSIZIOA saguarenPosizioa() { return saguPos; }