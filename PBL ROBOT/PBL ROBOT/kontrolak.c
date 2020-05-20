#include "kontrolak.h"
#include "sdlHasieratu.h"

SDL_Event event;

int ebentuaJasoGertatuBada()
{
    int ret = 0;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_W:
                ret = TECLA_w;
                break;
            case SDL_SCANCODE_D:
                ret = TECLA_d;
                break;
            case SDL_SCANCODE_A:
                ret = TECLA_a;
                break;
            case SDL_SCANCODE_S:
                ret = TECLA_s;
                break;
            case SDL_SCANCODE_ESCAPE:
                ret = TECLA_ESCAPE;
                break;
            case SDL_SCANCODE_UP:
                ret = TECLA_UP;
                break;
            case SDL_SCANCODE_DOWN:
                ret = TECLA_DOWN;
                break;
            case SDL_SCANCODE_RIGHT:
                ret = TECLA_RIGHT;
                break;
            case SDL_SCANCODE_LEFT:
                ret = TECLA_LEFT;
                break;
            case SDL_SCANCODE_E:
                ret = TECLA_e;
                break;
            case SDL_SCANCODE_0:
                ret = TECLA_0;
                break;
            case SDL_SCANCODE_1:
                ret = TECLA_1;
                break;
            default:
                ret = event.key.keysym.scancode;
                break;
            }
            break;
        case SDL_QUIT:
            ret = GERTAERA_IRTEN;
            break;
        case SDL_MOUSEBUTTONUP:
            switch (event.button.button) {
            case SDL_BUTTON_LEFT:
                ret = SAGU_BOTOIA_EZKERRA;
                break;
            case SDL_BUTTON_RIGHT:
                ret = SAGU_BOTOIA_ESKUMA;
                break;
            default:
                ret = event.button.button;
                break;
            }
            break;

        }
    }
    return ret;
}