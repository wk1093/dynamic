#include <stdio.h>
#include "dynamic.h"

createDynamicArray(float, FloatVec); 


int main() {
    FloatVec a = FloatVecNew();

    FloatVecAppend(&a, 1.0);
    FloatVecAppend(&a, 2.0);
    FloatVecAppend(&a, 3.0);

    for (int i = 0; i < FloatVecLen(&a); i++) {
        printf("%f\n", FloatVecGet(&a, i));
    }

    FloatVecClear(&a);

    FloatVecAppend(&a, 3.0);
    FloatVecAppend(&a, 2.0);
    FloatVecAppend(&a, 1.0);

    for (int i = 0; i < a.len; i++) {
        printf("%f\n", a.data[i]);
    }

    FloatVecDestroy(&a);
}