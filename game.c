#include "game.h"
#include "matrix.h"
#include <stdlib.h>

#include <stdint.h>

#define ALL_DEATH 0
#define GAME_LOOP 10

game* new_game(matrix* m){
   game* obj = (game*)malloc(sizeof(game));
   obj->grid = m;
   return obj;
}

void game_end(game* obj, int end_code){
    if(end_code == ALL_DEATH){
        printf("=======================\n");
        printf("GAME END! ALL CELL DEAD\n");
        printf("=======================\n");
    }
    else if(end_code == GAME_LOOP){
        printf("========================\n");
        printf("GAME END! YOU FOUND LOOP\n");
        printf("========================\n");
    }
    
    delete_matrix(obj->grid);
}

int count_alive_neighbors(matrix* m, int r, int c){
    int count=0;
    for(int i=r-1; i<=r+1; ++i){
        if(i == -1 || i == get_size(m)){
            continue;
        }
        for(int j=c-1; j<=c+1; ++j){
            if(j == -1 || j == get_size(m)){
                continue;
            }
            if(i == r && j == c){
                continue;
            }
            if(get_elem(m, i, j) == ALIVE_CELL){
                count++;
            }
        }
    }

    return count;
}

void get_next_generation(game* const obj){

    if(count_cell(obj->grid) == 0){
        game_end(obj, ALL_DEATH);
    }
    matrix* new_m = create_matrix(get_size(obj->grid));
    
    for(int i=0; i<get_size(obj->grid); ++i){
        for(int j=0; j<get_size(obj->grid); ++j){
            int live_cell = count_alive_neighbors(obj->grid, i, j);
            
            if(get_elem(obj->grid, i, j) == ALIVE_CELL){                                             
                if(live_cell == 3 || live_cell == 2){
                    set_elem(new_m, i, j, 1);
                }
                else{
                    set_elem(new_m, i, j, 0);
                }
                
            }
            else{
                if(live_cell == 3){
                    set_elem(new_m, i, j, 1);
                }
            }
        }
    }
    
    delete_matrix(obj->grid);
    obj->grid = new_m;
}

