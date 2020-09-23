#ifndef IO_TOOLS_H
#define IO_TOOLS_H

#ifndef MAXLEN
#define MAXLEN 200
#endif /* MAXLEN */

/** Job ID tag which is appended to the end of every output filenames. */
extern char job_id_tag[MAXLEN];

/** Write arrays in text format. */
void write_array(double *data, int size, char *filename);
void write_2D_array(double **data, int size1, int size2, char *filename);
void write_3D_array(double ***data, int size1, int size2, int size3,
                    char *filename);
void write_1D_int_array(int *data, int size, char *filename);
void write_2D_int_array(int **data, int size1, int size2, char *filename);
void write_2D_complex_array(complex double **data, int size1, int size2,
                            char *filename);

/** Reads array from a text file and returns its content and size */
double *read_array(char *filename, int *size);
int *read_int_array(char *filename, int *size);

/** Reads array from a binary, assuming certain array dimension(size) */
double *read_binary(char *filename, int size);


#endif /* IO_TOOLS_H */
