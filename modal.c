#include <stdio.h>
#include <stdlib.h>

#include "modal.h"


struct best_mode_struct {
    double **prim;
    double ***late_T;
    double ***late_E;
    bool orthonormalised;
}
