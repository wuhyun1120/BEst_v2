#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"

char job_id_tag[MAXLEN];


char *
full_path(char *filename)
{
    char path[MAXLEN];
    strcpy(path, output_directory);
    strcat(path, "/");
    strcat(path, filename);
    strcat(path, "_");
    strcat(path, job_id_tag);
    return path;
}


void
write_array(double *data, int size, char *filename)
{
    char *path = full_path(filename);

    FILE *output_file = fopen(path, "w");
    if (output_file == NULL){
        printf("Error opening file %s to write data\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(output_file, "%.14e\n", data[i]);
    }
    fclose(output_file);
    return;
}


void
write_2D_array(double **data, int size1, int size2, char *filename)
{
    char *path = full_path(filename);

    FILE *output_file = fopen(path, "w");
    if (output_file == NULL){
        printf("Error opening file %s to write data\n", filename);
        return;
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            fprintf(output_file, "%.14e ", data[i][j]);
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);
    return;
}


void
write_3D_array(double ***data, int size1, int size2, int size3, char *filename)
{
    char *path = full_path(filename);

    FILE *output_file = fopen(path, "w");
    if (output_file == NULL){
        printf("Error opening file %s to write data\n", filename);
        return;
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                fprintf(output_file, "%.14e\n", data[i][j][k]);
            }
        }
    }
    fclose(output_file);
    return;

}


void
write_1D_int_array(int *data, int size, char *filename)
{
    char *path = full_path(filename);

    FILE *output_file = fopen(path, "w");
    if (output_file == NULL){
        printf("Error opening file %s to write data\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(output_file, "%d\n", data[i]);
    }
    fclose(output_file);
    return;

}


void
write_2D_int_array(int **data, int size1, int size2, char *filename)
{

    char *path = full_path(filename);

    FILE *output_file = fopen(path, "w");
    if (output_file == NULL){
        printf("Error opening file %s to write data\n", filename);
        return;
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            fprintf(output_file, "%d ", data[i][j]);
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);
    return;


}


void 
write_2D_complex_array(complex double **data, int size1, int size2,
                       char *filename)
{
    char *path = full_path(filename);

    FILE *output_file = fopen(path, "w");
    if (output_file == NULL){
        printf("Error opening file %s to write data\n", filename);
        return;
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            double real = creal(data[i][j]);
            double imag = cimag(data[i][j]);
            fprintf(output_file, "%.14e+%.14ej ", real, imag);
        }
        fprintf(output_file, "\n");
    }
    fclose(output_file);
    return;
}


double *
read_array(char *filename, int *size)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s to read data\n", filename);
        exit(1);
    }

    double *arr = create_array(MAXLINES);
    char line[MAXLEN], **cptr = (char **) malloc(1 * sizeof(char *));
    int cnt = 0;
    while (fgets(line, MAXLEN, file)) {
        arr[cnt] = strtod(line, sptr);
        cnt++;
    }
    *size = cnt;
    fclose(file);

    return arr;
}


int *
read_int_array(char *filename, int *array_length)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s to read data\n", filename);
        exit(1);
    }

    int *arr = create_int_array(MAXLINES);
    char line[MAXLEN], **cptr = (char **) malloc(1 * sizeof(char *));
    int cnt = 0;
    while (fgets(line, MAXLEN, file)) {
        arr[cnt] = strtol(line, sptr);
        cnt++;
    }
    *size = cnt;
    fclose(file);

    return arr;
}


double *
read_binary(char *filename, int size)
{
    FILE *file;
    file = fopen("filename", "rb");
    if (file == NULL) {
        printf("Error opening file %s to read data\n", filename);
        exit(1);
    }

    double *data = create_array(size);
    fread(data, sizeof(double), size, file);
    fclose(file);

    return data;
}
