#include "renderer.h"
#include <SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <stdio.h>
#include <stdlib.h>

static inline uint32_t get_uint32_from_color(int r, int g, int b){
    return (255 << 24) | (r << 16) | (g << 8) | b;
}

static inline void draw_point(SimulationRenderer* renderer, int x, int y, uint32_t color){
    renderer->pixels[y * renderer->map_width + x] = color;
}

 SimulationRenderer* renderer_create_new_renderer(int screen_width, int screen_height, int map_width, int map_height){
    SimulationRenderer* renderer = malloc(sizeof(SimulationRenderer));
    renderer->screen_width = screen_width;
    renderer->screen_height = screen_height;
    renderer->map_width = map_width;
    renderer->map_height = map_height;

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
    // SET HINTS
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    // PIXELS
    renderer->pixels = malloc(sizeof(uint32_t)*renderer->map_width*renderer->map_height);
    renderer->pixels_texture = SDL_CreateTexture(renderer->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, renderer->map_width, renderer->map_height);

    for (int y = 0; y < renderer->map_height; y++) {
        for (int x = 0; x < renderer->map_width; x++) {
            uint8_t r = x % 255;
            uint8_t g = y % 255;
            uint8_t b = 150;
            // ARGB formatında pikseli oluştur (0xAARRGGBB)
            renderer->pixels[y * renderer->map_width + x] = (255 << 24) | (r << 16) | (g << 8) | b;
        }
    }
    SDL_UpdateTexture(renderer->pixels_texture, NULL, renderer->pixels, renderer->map_width * sizeof(uint32_t));

    return renderer;
}

void renderer_delete_renderer(SimulationRenderer *renderer){
    if(!renderer) return;
    if(renderer->renderer) SDL_DestroyRenderer(renderer->renderer);
    if(renderer->window) SDL_DestroyWindow(renderer->window);
    if(renderer->pixels_texture) SDL_DestroyTexture(renderer->pixels_texture);
    if(renderer->pixels) free(renderer->pixels);
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
                }else if(event.key.keysym.sym == SDLK_p) {
                    int x = rand() % renderer->map_width;
                    int y = rand() % renderer->map_height;

                    int r = rand() % 256;
                    int g = rand() % 256;
                    int b = rand() % 256;
                    draw_point(renderer, x, y, get_uint32_from_color(r, g, b));
                    SDL_UpdateTexture(renderer->pixels_texture, NULL, renderer->pixels, renderer->map_width * sizeof(uint32_t));
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
    SDL_RenderClear(renderer->renderer);
    SDL_RenderCopy(renderer->renderer, renderer->pixels_texture, NULL, NULL);
    SDL_RenderPresent(renderer->renderer);
}

