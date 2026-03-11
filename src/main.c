#include "renderer.h"
#include <SDL2/SDL_timer.h>
#include <stdio.h>

int main() {
    printf("heyy, welcome\n");

    SimulationRenderer* renderer = renderer_create_new_renderer(300, 300);
    SDL_Event event;
    for(;;){
        renderer_do_input(renderer);
        renderer_render(renderer);
        SDL_Delay(17);
    }
    return 0;
}

// I just want to feel better
// so i am programming this useless sh*t
//
// Just leave me alone
// I can't help my self
// But I'll try
// It's not your fault
//
// And I decide to kill the pain tonight
// I am looking for something to kill the pain tonight (and I found this useless sh*t to help me to feel better)
//
//
// I've searched all the universe and found my self within her eyes
//
//
// Adios
