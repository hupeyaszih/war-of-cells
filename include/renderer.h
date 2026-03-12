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

SimulationRenderer* renderer_create_new_renderer(int screen_width, int screen_height, int map_width, int map_height);
void renderer_render(SimulationRenderer* renderer);
void renderer_do_input(SimulationRenderer* renderer);

void renderer_delete_renderer(SimulationRenderer* renderer);

#endif
