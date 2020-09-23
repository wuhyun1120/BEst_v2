#ifndef ARRAY_TOOLS_H
#define ARRAY_TOOLS_H

#define MEM_ALIGNMENT 64    // Memory alignment in bytes

#include <complex.h>

/**
 * Creates a dynamic array with given dimensions.
 * The last index is always padded to ensure memory alignment.
 * Padded size for multidimensional arrays can be found either by
 * e.g. (&arr[0][0] - &arr[1][0]), or pad(d, MEM_ALIGNMENT / sizeof(dtype))
 */

int pad(const int n, const int pad_size);
double *create_array(int d1);
double **create_2D_array(int d1, int d2);
double ***create_3D_array(int d1, int d2, int d3);

int *create_int_array(int d1);
int **create_2D_int_array(int d1, int d2);

complex double **create_2D_complex_array(int d1, int d2);

void free_array(void *arr);
void free_2D_array(void **arr);
void free_3D_array(void ***arr);

#endif /* ARRAY_TOOLS_H */
