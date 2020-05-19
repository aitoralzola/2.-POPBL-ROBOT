#define _CRT_SECURE_NO_WARNINGS
#include "sdlHasieratu.h"
#include "irudiak.h"
#include "kontrolak.h"

int main(int argc, char** argv) {
    int errorea, irudia = 0, robot = 0;
    int itxi;

    errorea = SDLHasi();
    if (errorea == 0) {
        printf("Errorea lehioa sortzerakoan.\n");
    }
    else {
        do {
            if (irudia == 0 && robot == 0) {
                irudia = irudiaSortu(BARRUALDEA);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
                robot = irudiaSortu(ROBOT);
                irudiakMarraztu();
                SDL_RenderPresent(gRenderer);
            }
            itxi = ebentuaJasoGertatuBada();
        } while (itxi != TECLA_ESCAPE);
    }

    return 0;
}