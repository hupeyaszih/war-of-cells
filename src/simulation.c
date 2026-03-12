#include "simulation.h"
#include <stdlib.h>
#include <string.h>


Simulation* simulation_new_simulation(int map_width, int map_height){
    Simulation* simulation = malloc(sizeof(Simulation));

    simulation->map_width = map_width;
    simulation->map_height = map_height;

    simulation->cell_count = map_width * map_height;
    simulation->cells = malloc(sizeof(uint16_t) * simulation->cell_count);
    simulation->cell_buffer = malloc(sizeof(uint16_t)*simulation->cell_count);
    return simulation;
}

void simulation_delete_simulation(Simulation *simulation){
    if(simulation->cells) free(simulation->cells);
    if(simulation->cell_buffer) free(simulation->cell_buffer);
    if(simulation) free(simulation);
    simulation = NULL;
}

void simulation_update(Simulation* restrict simulation){
    simulation->cell_buffer = memcpy(simulation->cell_buffer, simulation->cells, sizeof(uint16_t)*simulation->cell_count);
}
