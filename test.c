#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>



int main(){
matrix* m = create_matrix(10);
set_elem(m, 2, 3, 1);
int r = count_cell(m);
printf("%d", r);
return 0;
}