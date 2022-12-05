#include <stdio.h>
#include <stdlib.h>
///////////////////////// EXAMPLE /////////////////////////

// #include "dynvec.h"

// int main() {
//     Vec(int) a = VecNew(int); // creates a struct that stores the data, size, and capacity
//     VecAppend(a, 1); // Will add to the array, and allocate more memory if required
//     VecAppend(a, 2);
//     VecAppend(a, 3);
//     VecAppend(a, 4);

//     VecPrint(a); // [1, 2, 3, 4]

//     VecClear(a);

//     VecAppend(a, 5);
//     VecAppend(a, 6);
//     VecAppend(a, 7);

//     VecPrint(a); // [5, 6, 7]
    
//     VecInsert(a, 1, 0);

//     VecPrint(a); // [5, 0, 6, 7]

//     VecDestroy(a);
//     return 0;
// }

#define Vec(t) struct {t* data; int len; int cap;}
#define VecNew(t) {malloc(sizeof(t)), 0, 1}
#define VecAppend(v, val) {if (v.len == v.cap) {v.cap *= 2; v.data = realloc(v.data, v.cap * sizeof(val));} v.data[v.len++] = val;}
#define VecDestroy(v) free(v.data); v.data = NULL; v.len = v.cap = 0;
#define VecGet(v, i) v.data[i]
#define VecSet(v, i, val) v.data[i] = val
#define VecLen(v) v.len
#define VecClear(v) v.len = 0
#define VecPop(v) v.data[--v.len]
#define VecLast(v) v.data[v.len - 1]
#define VecFirst(v) v.data[0]
#define VecInsert(v, i, val) {if (v.len == v.cap) {v.cap *= 2; v.data = realloc(v.data, v.cap * sizeof(val));} for (int j = v.len; j > i; j--) v.data[j] = v.data[j - 1]; v.data[i] = val; v.len++;}
#define VecRemove(v, i) {for (int j = i; j < v.len - 1; j++) v.data[j] = v.data[j + 1]; v.len--;}
#define VecIter(v, i) for (int i = 0; i < v.len; i++)
#define VecIterRev(v, i) for (int i = v.len - 1; i >= 0; i--)
#define VecPrint(v) printf("["); VecIter(v, i) {if (i != v.len-1) printf("%d, ", v.data[i]); else printf("%d", v.data[i]);} printf("]\n");
#define VecPrintln(v) VecIter(v, i) printf("%d\n", v.data[i]);