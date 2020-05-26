#include "sdlHasieratu.h"
#ifndef IRUDIAK_H
#define IRUDIAK_H

#define MAX_IMG 50

//----------------------------------------------------------------
#define BARRUALDEA ".\\IMG\\Barrualdea.bmp"
#define TERRAZA ".\\IMG\\terraza.bmp"
#define ROBOT ".\\IMG\\Errobota.bmp"
#define MENU ".\\IMG\\MENU.bmp"
#define PERTSONA ".\\IMG\\pertsona.bmp"


typedef struct
{
    int id;
    SDL_Surface* imagen;
    SDL_Texture* texture;
    SDL_Rect dest;
}IMG;

int irudiaSortu(char* imgName);
int irudiaKargatu(char* fileName);
void irudiaKendu(int id);
int irudiarenPosizioaAurkitu(int id);
void pantailaGarbitu();
void irudiaMugitu(int numImg, int x, int y);
void irudiakMarraztu();
#endif