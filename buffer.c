#include "buffer.h"
#include <stdlib.h>
#include "matrix.h"


#define BUF_SIZE 32

struct matrix_buf{
  matrix** data;
  size_t capacity;
  size_t count;
  size_t head;
};

matrix_buf* buffer_create(){
    matrix_buf* buf = malloc(sizeof(matrix_buf));
    if(buf == NULL){
        return NULL;
    }
    buf->data = calloc(BUF_SIZE, sizeof(matrix*));
    buf->capacity = BUF_SIZE;
    buf->count = 0;
    buf->head = 0;
    return buf;
}

void buffer_delete(matrix_buf* buf){
    for(int i = 0; i < get_buf_capacity(buf); ++i){
        free(buf->data[i]);
    }
}

void matrix_in_buf(matrix* m, matrix_buf* buf){
        buf->data[buf->head] = m;
        buf->head = (buf->head+1) % buf->capacity;
}

int get_buf_count(matrix_buf* buf){
    return buf->count;
}
void inc_count(matrix_buf* buf){
    buf->count+=1;
}
int get_buf_head(matrix_buf* buf){
    return buf->head;
}
void inc_buf_head(matrix_buf* buf){
    buf->head+=1;
}
int get_buf_capacity(matrix_buf* buf){
    return buf->capacity;
}
