#include "sdlHasieratu.h"

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* gRenderer;
/* AUDIOA */
Mix_Music* gMusic = NULL;

TTF_Font* font = 0;

int SDLHasi()
{
    int hasieratua = 0;


    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    //Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    else
    {
        gMusic = Mix_LoadMUS(".\\Sounds\\mariobros.wav");
        if (gMusic == NULL)
        {
            printf("Ezin izan da musika kargatu. SDL_mixer Error: %s\n", Mix_GetError());
        }
        Mix_PlayMusic(gMusic, -1);

        window = SDL_CreateWindow("MUrio Bros", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);
        gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(window);
            hasieratua = 1;
        }
    }

    return hasieratua;
}

int irudiaMarraztu(SDL_Texture* texture, SDL_Rect* pDest)
{
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = pDest->w;
    src.h = pDest->h;
    SDL_RenderCopy(gRenderer, texture, &src, pDest);

    return 0;
}

void bukatu()
{
    //Free the music
    Mix_FreeMusic(gMusic);
    gMusic = NULL;
    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;
    //Quit SDL subsystems
    Mix_Quit();
    SDL_Quit();
}