#define _CRT_SECURE_NO_WARNINGS
#include "sdlHasieratu.h"
#include "funtzioak.h"

int main(int argc, char** argv) {
    int errorea, egoera;

    errorea = SDLHasi();
    if (errorea == 0) {
        printf("Errorea lehioa sortzerakoan.\n");
    }
    else {
        do {
            egoera = hasiPrograma();
        } while (egoera != -1);
        bukatu();
    }

    return 0;
}