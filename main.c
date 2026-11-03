#include <stdio.h>
#include "game.h"
#include <time.h>
#include "matrix.h"
#include <raylib.h>
#define PIXEL_SIZE 20
#define HEIGHT 1000
#define WEIGHT 1000

typedef struct{
    float progress;
    int x;
    int y;
    int direction;
    bool is_finished;
    float duration;
}animation;

void draw_matrix(game* obj){
    for(int y = 0; y < get_size(obj->grid); ++y){
        for(int x = 0; x < get_size(obj->grid); ++x){
            if(get_elem(obj->grid, x, y) == ALIVE_CELL){
                DrawRectangle(x*PIXEL_SIZE, y*PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE, PINK);
            }  
        }
    }
}
void end_screen(){
    
}

void next_gen(game* obj){
    int res = get_next_generation(obj);
    if(res == 0){
        ClearBackground(BLACK);
        DrawText("GAME OVER", HEIGHT/2, WEIGHT/2, 10, WHITE);
        DrawText("ALL CELL DEATH", HEIGHT/2, WEIGHT/2, 10, WHITE);
    }
    else{
        matrix_in_buf(obj->grid);
        draw_matrix(obj);
        
    }
}

void past_gen(game* obj){
    
}


int main(){
    int enter_flag;
    matrix* m = create_matrix(HEIGHT/PIXEL_SIZE);
    game* obj = new_game(m); 
    coords* buf = buffer_create();
    InitWindow(HEIGHT,WEIGHT, "game live");
    SetTargetFPS(60);
    while(!WindowShouldClose()){ // first loop
        BeginDrawing();
        ClearBackground(BLACK);
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){ 
            Vector2 coords = GetMousePosition();
            coords.x = coords.x/PIXEL_SIZE;
            coords.y = coords.y/PIXEL_SIZE;
            if(get_elem(obj->grid,coords.x, coords.y) == 1){
                set_elem(obj->grid, coords.x, coords.y, 0);
            }
            else{
                set_elem(obj->grid, coords.x, coords.y, 1);
            }
        }
        if(IsKeyPressed(KEY_ENTER)){
            enter_flag = 1;
        }
        draw_matrix(obj);
        EndDrawing();
        if(enter_flag == 1){
            break;
        }
        
    }
    time_t start = time(NULL);
    int res = CONTINUE_GAME;
    // main loop
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        int key = GetKeyPressed();
        switch (key){
            case KEY_D:
                next_gen(obj);
            case KEY_A:
                past_gen(obj);
            case KEY_Q:
                end_screen();                            
        }
        EndDrawing();
    }

    return 0;
}