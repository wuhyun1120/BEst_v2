#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include "array_tools.h"

int
pad(const int n, const int pad_size) 
{
    if (n % pad_size == 0)
        return n;
    else
        return (n / pad_size + 1) * pad_size;
}

static void *
aligned_malloc(const size_t size)
{
    void *ptr;
    size_t padded_size = pad(size, MEM_ALIGNMENT);

#if defined (__INTEL_COMPILER)
    ptr = _mm_malloc(padded_size, MEM_ALIGNMENT);
#else
    ptr = aligned_alloc(MEM_ALIGNMENT, padded_size);
#endif /* defined (__INTEL_COMPILER) */

    if (!ptr) {
        printf("Out of Memory\n");
        exit(1);
    }
    return ptr;
}

static void
aligned_free(void *ptr)
{
#if defined (__INTEL_COMPILER)
    _mm_free(ptr);
#else
    free(ptr);
#endif /* defined (__INTER_COMPILER) */
}


double *
create_array(int d1)
{
    double *arr = (double *) aligned_malloc(d1 * sizeof(double));
    return arr;
}

double **
create_2D_array(int d1, int d2)
{
    int d2pad = pad(d2, MEM_ALIGNMENT / sizeof(double));

    double **arr;
    arr = (double **) aligned_malloc(d1 * sizeof(double *));
    arr[0] = (double *) aligned_malloc(d1 * d2pad * sizeof(double));

    for (int i = 0; i < d1; i++) {
        arr[i] = arr[0] + i * d2pad; 
    }
    return arr;
}
 
double ***
create_3D_array(int d1, int d2, int d3)
{
    int d3pad = pad(d3, MEM_ALIGNMENT / sizeof(double));

    double ***arr;
    arr = (double ***) aligned_malloc(d1 * sizeof(double **));
    arr[0] = (double **) aligned_malloc(d1 * d2 * sizeof(double *));
    arr[0][0] = (double *) aligned_malloc(d1 * d2 * d3pad * sizeof(double));

    for (int i = 0; i < d1; i++) {
        arr[i] = arr[0] + i * d2;
        for (int j = 0; j < d2; j++) {
            arr[i][j] = arr[0][0] + (d2 * i + j) * d3pad;
        }
    }
    return arr;
}

int *
create_int_array(int d1)
{
    return (int *) aligned_malloc(d1 * sizeof(int));
}

int **
create_2D_int_array(int d1, int d2)
{
    int d2pad = pad(d2, MEM_ALIGNMENT / sizeof(int));

    int **arr;
    arr = (int **) aligned_malloc(d1 * sizeof(int *));
    arr[0] = (int *) aligned_malloc(d1 * d2pad * sizeof(int));

    for (int i = 0; i < d1; i++) {
        arr[i] = arr[0] + i * d2pad; 
    }
    return arr;
}

complex double **
create_2D_complex_array(int d1, int d2)
{
    int d2pad = pad(d2, MEM_ALIGNMENT / sizeof(complex double));

    complex double **arr;
    const size_t size1 = d1 * sizeof(complex double *);
    const size_t size2 = d1 * d2pad * sizeof(complex double);
    arr = (complex double **) aligned_malloc(size1);
    arr[0] = (complex double *) aligned_malloc(size2);

    for (int i = 0; i < d1; i++) {
        arr[i] = arr[0] + i * d2pad; 
    }
    return arr;
}

void
free_array(void *arr)
{
    aligned_free(arr);
}

void
free_2D_array(void **arr)
{
    aligned_free(arr[0]);
    aligned_free(arr);
}

void
free_3D_array(void ***arr)
{
    aligned_free(arr[0][0]);
    aligned_free(arr[0]);
    aligned_free(arr);
}
