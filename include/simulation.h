#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdint.h>

typedef struct {
    int map_width, map_height;

    uint16_t* cells;
    uint16_t* cell_buffer;
    int32_t cell_count;
} Simulation;

Simulation* simulation_new_simulation(int map_width, int map_height);
void simulation_delete_simulation(Simulation* simulation);

void simulation_update(Simulation* simulation);

// CELL
uint16_t cell_create_cell(int team);

#endif
