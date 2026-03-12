#ifndef GLOBALS_H
#define GLOBALS_H

#define DEBUG

#ifdef DEBUG
#include "stdio.h"
#define LOG(fmt, ...) printf("[LOG] " fmt "\n", ##__VA_ARGS__)
#define LOG_ERR(fmt, ...) printf("[ERR] " fmt "\n", ##__VA_ARGS__)
#define LOG_INT(x) printf("[LOG] %d", x)
#else
#define LOG(...) 
#define LOG_INT(x) 
#endif

enum CELL_TEAM {
    RED,
    BLUE
};

#endif
