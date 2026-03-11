#include "renderer.h"
#include <SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <stdio.h>
#include <stdlib.h>

 SimulationRenderer* renderer_create_new_renderer(int screen_width, int screen_height){
    SimulationRenderer* renderer = malloc(sizeof(SimulationRenderer));
    renderer->screen_width = screen_width;
    renderer->screen_height = screen_height;

    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    renderer->window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, renderer->screen_width, renderer->screen_height, windowFlags);

    if (!renderer->window)
    {
        printf("Failed to open %d x %d window: %s\n", renderer->screen_width, renderer->screen_height, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    renderer->renderer = SDL_CreateRenderer(renderer->window, -1, rendererFlags);

    if (!renderer->renderer)
    {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
    return renderer;
}

void renderer_delete_renderer(SimulationRenderer *renderer){
    if(!renderer) return;
    if(renderer->renderer) SDL_DestroyRenderer(renderer->renderer);
    if(renderer->window) SDL_DestroyWindow(renderer->window);
    if(renderer) free(renderer);
    renderer = NULL;
}


void renderer_do_input(SimulationRenderer* renderer){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch (event.type)
        {
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    printf("but you forgot something..\n You did not say \"goodbye\" :(\n");
                    exit(0);
                }
                break;

            case SDL_QUIT:
                printf("adios\n");
                exit(0);
                break;
            default:
                break;
        }
    }
}

void renderer_render(SimulationRenderer* renderer){
    SDL_SetRenderDrawColor(renderer->renderer, 48, 48, 48, 255);
    SDL_RenderClear(renderer->renderer);

    SDL_RenderPresent(renderer->renderer);
}

