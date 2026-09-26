#ifndef GAME_H
#define GAME_H
#include "matrix.h"
#define ALIVE_CELL 1
#define DEAD_CELL 0

typedef struct{
    matrix* grid; 
    int* hash_data[50];
}game;

game* new_game(matrix* m);
void get_next_generation(game* m);
int count_alive_neighbors(matrix* m, int r, int c);

#endif