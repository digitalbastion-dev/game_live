#include <stdio.h>
#include "game.h"
#include "matrix.h"


int main(){
    matrix* m = create_matrix(5);
    set_elem(m, 2, 1, 1);
    set_elem(m, 2, 2, 1);
    set_elem(m, 2, 3, 1);
    game* obj = new_game(m);
    for(int i=0; i < 10; ++i){
        get_next_generation(obj);
        print_matrix(obj->grid);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    }
}