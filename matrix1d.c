#include "matrix.h"
#include <stdlib.h>
#include <stdint.h>


struct matrix {
    int* data;
    int size;
    int hash;
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

int matrix_CRC32_hesher(int* matrix_line, matrix* m){
    if(matrix_line == NULL){
        return 1;
    }
    uint32_t polynomial = 0xEDB88320;
    uint32_t CRC32_result = 0xFFFFFFFF;
    for(int i = 0; i < m->size*m->size; ++i){
        CRC32_result ^= matrix_line[i];
        for(int bit = 0; bit < 32; ++bit){
            if(CRC32_result & 1){
                CRC32_result = (CRC32_result >> 1) ^ polynomial;
            }
            else{
                CRC32_result >>= 1;
            }
        }
    }
     m->hash = CRC32_result ^ 0xFFFFFFFF;
     return 0;
}

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