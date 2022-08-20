#include "random.h"
#include <stdio.h>
#include <stdlib.h>

double random_double() {
    //fprintf(stderr, "%f\n", rand()/(double) (RAND_MAX + 1.0));
    return rand()/(double) (RAND_MAX + 1.0);
}

double random_min_max(double min, double max) {
    return min + (max - min)*random_double();
}