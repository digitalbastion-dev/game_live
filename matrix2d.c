#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct matrix{
    int** data;
    int size;
    int hash;
};



matrix* create_matrix(const int size){
    matrix* m;
    m = (matrix*)malloc(sizeof(matrix));
    if(m == nullptr){
        fprintf(stderr, "ERR: create struct fault");
        return nullptr;
    }
    m->size = size;
    m->data = (int**)malloc((m->size)*sizeof(int*)); 
    
    for(int i=0;i<m->size;++i){
        m->data[i] = (int*)calloc((m->size), sizeof(int));
    }

    return m;

}

void delete_matrix(matrix* m){
    for(int i=0; i<m->size;++i){
        free(m->data[i]);
    }

   free(m->data);
   free(m);
    
}

int* buffer_create(int size){
    int* buffer = calloc(size, sizeof(int));
    if(buffer == NULL){
        return NULL;
    }
    return buffer;
}

void buffer_delete(int* buffer){
    free(buffer);
}

int* matrix_in_line(matrix* m){
    int size = m->size*m->size;
    int* matrix_line = buffer_create(size);
    if(matrix_line == NULL){
        return NULL;
    }
    int index = 0;
        for (int i = 0; i < m->size; ++i) {
            for (int j = 0; j < m->size; ++j) {
                matrix_line[index] = m->data[i][j];
                index+=1;
            }
        }
    return matrix_line;
}

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

int hash_get(matrix *m){
    return m->hash;
}

int get_elem(const matrix* const m,int r, int c){
    return m->data[r][c];
}

void set_elem(matrix* const m, int r, int c, int value){
    m->data[r][c] = value;
}

int get_size(const matrix* m){
    return m->size;
}

int count_cell(matrix* const m){
    int count = 0;
    for(int i=0;i<m->size;++i){
        for(int j=0;j<m->size;++j){
            count+=m->data[i][j];
        }
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

void print_matrix(matrix* m){
    for(int i=0; i < m->size; ++i){
        for(int j=0; j < m->size; ++j){                       
            printf("%d", m->data[i][j]);
            
        }
        printf("\n");
    }
}

void copy_matrix(matrix* m, matrix* new_m){
    new_m->size = m->size;
    for(int i=0; i < m->size; ++i){
        for(int j=0; j < m->size; ++j){
            new_m->data[i][j] = m->data[i][j];
        }
    }
}