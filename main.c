#include <stdio.h>
#include "libs/vector.h"
#include <stdint.h>
#include "libs/vector.h"

int main () {
    vector v = createVector (4 ) ;

    printf("%d", getVectorValue(&v,6));
    deleteVector(&v);
    return 0;
    }