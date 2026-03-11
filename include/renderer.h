#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

typedef struct {
    int screen_width, screen_height;
    SDL_Window* window;
    SDL_Renderer* renderer;
} SimulationRenderer;

SimulationRenderer* renderer_create_new_renderer(int screen_width, int screen_height);
void renderer_render(SimulationRenderer* renderer);
void renderer_do_input(SimulationRenderer* renderer);

void renderer_delete_renderer(SimulationRenderer* renderer);

#endif
