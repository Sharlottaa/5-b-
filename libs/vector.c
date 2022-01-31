#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "vector.h"

vector createVector(size_t n){
    int *a=(int *) malloc(sizeof (int)*n);
    if(NULL==a){
        fprintf ( stderr , "bad alloc ") ;
        exit (1) ;
    }
    return (vector){a, 0, n};
}