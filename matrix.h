#include <stdio.h>
#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix matrix;

/*
typedef struct{
    int* data;
    int size;
}matrix;
*/

matrix* create_matrix(const int size);
void delete_matrix(matrix* m);
int get_elem(const matrix* const m,int r, int c);
void set_elem(matrix* const m, int r, int c, int value);
matrix* matrix_sum(const matrix* const m, const matrix* const m2);
matrix* matrix_mul(const matrix* const m, int value);
void print_matrix(matrix* m);
int get_size(const matrix* m);
void vector_mul(const matrix* const m, int size, int vector);
int count_cell(matrix* const m);
void copy_matrix(matrix* m, matrix* new_m);
#endif
