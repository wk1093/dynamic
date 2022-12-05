#include <stdlib.h>
///////////////////////// EXAMPLE /////////////////////////

// #include <stdio.h>
// #include "dynarr.h"
// createDynamicArray(float, FloatVec); // Must be done in global scope (creates types and functions)


// int main() {
//     FloatVec a = FloatVecNew();

//     FloatVecAppend(&a, 1.0);
//     FloatVecAppend(&a, 2.0);
//     FloatVecAppend(&a, 3.0);

//     for (int i = 0; i < FloatVecLen(&a); i++) {
//         printf("%f\n", FloatVecGet(&a, i));
//     }

//     FloatVecClear(&a);

//     FloatVecAppend(&a, 3.0);
//     FloatVecAppend(&a, 2.0);
//     FloatVecAppend(&a, 1.0);

//     for (int i = 0; i < a.len; i++) {
//         printf("%f\n", a.data[i]);
//     }

//     FloatVecDestroy(&a);
// }

#define createDynamicArray(type, name) typedef struct { type* data; int len; int cap; } name; name name##New() { name d; d.len = 0; d.cap = 1; d.data = (type*)malloc(sizeof(type) * d.cap); return d; } void name##Append(name* d, type val) { if (d->len == d->cap) { d->cap *= 2; d->data = (type*)realloc(d->data, sizeof(type) * d->cap); } d->data[d->len] = val; d->len++; } void name##Destroy(name* d) { free(d->data); d->len = 0; d->cap = 0; } void name##Clear(name* d) { d->len = 0; } int name##Len(name* d) { return d->len; } type name##Get(name* d, int i) { if (i <= d->len) { return d->data[i]; } else { return d->data[0]; } } void name##Set(name* d, int i, type val) { if (i <= d->len) { d->data[i] = val; } } void name##Remove(name* d, int i) { if (i <= d->len) { for (int j = i; j < d->len - 1; j++) { d->data[j] = d->data[j + 1]; } d->len--; } }