#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sdlHasieratu.h"
#include "irudiak.h"
#include "kontrolak.h"
#include "funtzioak.h"
#include "dijkstra.h"

POSIZIOA saguPos;

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
    MAHAIAK* burua = NULL;
    PERTSONAK* pertson = NULL, *ptrAuxP;
    int itxi, fondoa, robot, per;
    char* str = { "matriz_barrualdea.txt" }, * mahaiak = { "robot_barrualdea.txt" }, * pertsona = {"pertsona_barrualdea.txt"};
    V = 12, hasi = 0;

    irudiakJarri(&robot, &fondoa);
    matrizeaOsatu(str);
    mahaienPosizioa(&burua, mahaiak);
    pertsonenPosizioa(&pertson, pertsona);
    dijkstra();
    do {
        end = mahaiaItzuliBarruan();
    } while (end == 0);
    posizioaAurkitu(pertson, &ptrAuxP);
    pertsonaKokatu(&per, ptrAuxP);
    pantailaratu(burua, &robot, end);
    memoriaGarbitu(&burua);

    do {
        itxi = ebentuaJasoGertatuBada();
    } while (itxi != TECLA_ESCAPE);
    if (itxi == TECLA_ESCAPE) {
        irudiakEzabatu(&per, &fondoa, &robot);
    }
}

void terraza() {
    MAHAIAK* burua = NULL;
    PERTSONAK* pertson = NULL, *ptrAuxP;
    int itxi, fondo, robot, per;
    char* str = { "matriz_terraza.txt" }, * mahaiak = { "robot_terraza.txt" }, * pertsona = { "pertsona_terraza.txt" };
    V = 7, hasi = 0;
    
    irudiakJarri(&robot, &fondo);
    matrizeaOsatu(str);
    mahaienPosizioa(&burua, mahaiak);
    pertsonenPosizioa(&pertson, pertsona);
    dijkstra();
    do {
        end = mahaiaItzuliTerraza();
    } while (end == 0);
    posizioaAurkitu(pertson, &ptrAuxP);
    pertsonaKokatu(&per, ptrAuxP);
    pantailaratu(burua, &robot, end);
    memoriaGarbitu(&burua);

    do {
        itxi = ebentuaJasoGertatuBada();
    } while (itxi != TECLA_ESCAPE);
    if (itxi == TECLA_ESCAPE) {
        irudiakEzabatu(&per, &fondo, &robot);
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
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 188) && (saguPos.x < 327) && (saguPos.y > 200) && (saguPos.y < 353)) mahai = 3;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 199) && (saguPos.x < 345) && (saguPos.y > 400) && (saguPos.y < 544)) mahai = 4;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 510) && (saguPos.x < 658) && (saguPos.y > 400) && (saguPos.y < 547)) mahai = 5;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 505) && (saguPos.x < 647) && (saguPos.y > 200) && (saguPos.y < 353)) mahai = 6;

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

void pertsonenPosizioa(PERTSONAK** burua, char* pertsona) {
    FILE* fp;
    PERTSONAK* ptrAux;

    fp = fopen(pertsona, "r");
    if (fp != NULL) {
        do {
            ptrAux = (PERTSONAK*)malloc(sizeof(PERTSONAK));
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

void posizioaAurkitu(PERTSONAK* buruaP, PERTSONAK** ptrAuxP) {
    int kont = V - 1;

    *ptrAuxP = buruaP;

    while (kont > end && *ptrAuxP != NULL) {
        buruaP = buruaP->ptrHurrengoa;
        *ptrAuxP = buruaP;
        kont--;
    }
}

void pertsonaKokatu(int* pertsona, PERTSONAK* ptrAux) {
    *pertsona = irudiaSortu(PERTSONA);
    irudiaMugitu(*pertsona, ptrAux->x, ptrAux->y);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
}

void pantailaratu(MAHAIAK* buruMahai, int* robot, int end) {
    MAHAIAK* ptrAuxM;

    if (end != hasi) {
        pantailaratu(buruMahai, robot, parent[end]);
    }
    ptrAuxM = mahaiaAurkitu(buruMahai, end);
    mugimendua(ptrAuxM, robot);
}

MAHAIAK* mahaiaAurkitu(MAHAIAK* buruMahai, int node) {
    MAHAIAK* ptrAux = buruMahai;
    int kont = V - 1;

    while (kont > node) {
        ptrAux = ptrAux->ptrHurrengoa;
        kont--;
    }

    return ptrAux;
}

void mugimendua(MAHAIAK* ptrAux, int* robot) {
    static int aurrekoX, aurrekoY;
    POSIZIOA pos;

    if (ptrAux == NULL) {
        aurrekoX = 660;
        aurrekoY = 30;
    }
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