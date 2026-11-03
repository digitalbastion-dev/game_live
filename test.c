#include "game.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>



int main(){

    matrix* m = create_matrix(1000);
    game* obj = new_game(m);

    matrix_buf* buf = buffer_create();
    matrix_in_buf(obj->grid, buf);
    
    
    
    return 0;
}