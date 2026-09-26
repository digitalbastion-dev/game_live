#include "matrix.h"
#include <stdlib.h>
#include <stdint.h>

struct matrix{
   int long long;
   int size;
};



matrix* create_matrix(const int size){
       
}
    
void delete_matrix(matrix* m);
int get_elem(const matrix* const m,int r, int c);
void set_elem(matrix* const m, int r, int c, int value);
matrix* matrix_sum(const matrix* const m, const matrix* const m2);
matrix* matrix_mul(const matrix* const m, int value);
