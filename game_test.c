#include "game.h"
#include "matrix.h"
#include <stdio.h>

int count_alive_neighbors_regular_test(){
    matrix* m = create_matrix(5);
    set_elem(m, 2, 1, 1);
    set_elem(m, 2, 2, 1);
    set_elem(m, 1, 2, 1);

    int expected = count_alive_neighbors(m, 2, 2);

    if(expected != 2){
        return 1;
    }
    
    return 0;
    delete_matrix(m);
}

int count_alive_neighbors_border_test(){
    matrix* m = create_matrix(5);
    set_elem(m, 0, 4, 1);
    set_elem(m, 4, 4, 1);
    set_elem(m, 3, 4, 1);
    int expected = count_alive_neighbors(m, 4, 4);
    if(expected != 1){
        return 1;
    } 
    return 0;
    delete_matrix(m);
}

int game_ender_test(){
    matrix* m = create_matrix(4);
    game* obj = new_game(m);
    get_next_generation(obj);
    
}
  
int count_alive_neighbors_test(){
    if(count_alive_neighbors_regular_test() == 1){
        printf("\033[31mregular test failed\0330m\n");
    }
    else{
        printf("\033[32mtest pass\0330\n");
    }

    if(count_alive_neighbors_border_test() == 1){
        printf("\033[31mregular test failed\0330m\n");
    }
    else{
        printf("\033[32mtest 2 pass\0330\n");
    }
}
void count_cell_test(){
    matrix* m = create_matrix(10);
    matrix* m2 = create_matrix(10);
    set_elem(m2, 4, 3, 1);
    set_elem(m2, 4, 4, 1);
    set_elem(m2, 5, 3, 1);
    

    if(count_cell(m) == 0){
        printf("all zero test pass\n");
    }
    else{
        printf("all zero test failed\n");
    }
    if(count_cell(m2) == 3){
        printf("one 1 test pass\n");
    }
    else{
        printf("one 1 test failed\n");
    }
}

void copy_matrix_test(){
    matrix* m = create_matrix(10);
    matrix* m2 = create_matrix(10);
    set_elem(m, 1, 1, 1);
    set_elem(m, 5, 4, 1);

    copy_matrix(m, m2);
    print_matrix(m);
    printf("\n");
    printf("\n");
    print_matrix(m2);
    if(count_cell(m2) == 2){
        printf("copy matrix test pass\n");
    }
    else{
        printf("copy matrix test failed\n");
    }
    
}
int main(){
    copy_matrix_test();
    return 0;
}