#include "matrix.h"
#include <stdlib.h>


struct matrix {
    int* data;
    int size;
};

matrix* create_matrix(const int size){
    matrix* m = malloc(sizeof(matrix));
    m->size = size;
    m->data = calloc(m->size*m->size, sizeof(int));

    return m;
}

int get_size(const matrix *m){
    return m->size;
}

void delete_matrix(matrix* m){
    free(m);
}

int get_elem(const matrix* const m,int r, int c){
    return m->data[m->size * r + c];
}

void set_elem(matrix* m, int r, int c, int value){
    m->data[r * m->size + c] = value;
}

int count_cell(matrix* const m){
    int count = 0;
    for(int i=0;i<m->size;++i){
        count+=m->data[i];
    }
    return count;
}

matrix* matrix_sum(const matrix* const m, const matrix* const m2){
    matrix* new_m = create_matrix(m->size);
    for(int i=0; i < get_size(m); ++i){
        for(int j=0; j < get_size(m); ++j){
            int value = get_elem(m, i, j) + get_elem(m2, i, j);
            set_elem(new_m, i, j, value);
            }
    }
    return new_m;
}
matrix* matrix_mul(const matrix* const m, int value);

void copy_matrix(matrix* m, matrix* new_m){
    for(int i=0; i < m->size; ++i){
        new_m->data[i] = m->data[i];
    }
}

void print_matrix(matrix *m){
    for(int i=0; i < m->size; ++i){
        for(int j=0; j < m->size; ++j){
            if(j == m->size-1){
                printf("%d\n", get_elem(m, i, j));
            }
            else{
                printf("%d", get_elem(m, i, j));
            }
        }
    }
}