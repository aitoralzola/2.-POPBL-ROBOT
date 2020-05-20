#define _CRT_SECURE_NO_WARNINGS
#include "sdlHasieratu.h"
#include "irudiak.h"
#include "kontrolak.h"
#include "funtzioak.h"

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

    barrua = irudiaSortu(BARRUALDEA);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
    robot = irudiaSortu(ROBOT);
    irudiaMugitu(robot, 100, 100);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
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

    terraza = irudiaSortu(TERRAZA);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
    robot = irudiaSortu(ROBOT);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);
    do {
        itxi = ebentuaJasoGertatuBada();
    } while (itxi != TECLA_ESCAPE);
    if (itxi == TECLA_ESCAPE) {
        irudiaKendu(terraza);
        irudiaKendu(robot);
        pantailaGarbitu();
    }
}