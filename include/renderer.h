#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL_render.h>

typedef struct {
    int screen_width, screen_height;
    int map_width, map_height;
    SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* pixels_texture;
    uint32_t* pixels;
} SimulationRenderer;

SimulationRenderer* renderer_create_new_renderer(const int screen_width, const int screen_height, const int map_width, const int map_height);
int renderer_render(const SimulationRenderer* restrict renderer);
int renderer_do_input(const SimulationRenderer* restrict renderer);

void renderer_delete_renderer(SimulationRenderer* renderer);

#endif
