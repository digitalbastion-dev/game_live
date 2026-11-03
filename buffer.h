#include "matrix.h"
#include "game.h"


void matrix_in_buf(matrix* m, matrix_buf* buf);
matrix_buf* buffer_create();
void buffer_delete(matrix_buf* buf);
int get_buf_count(matrix_buf* buf);
void inc_count(matrix_buf* buf);
int get_buf_head(matrix_buf* buf);
void inc_buf_head(matrix_buf* buf);
int get_buf_capacity(matrix_buf* buf);
