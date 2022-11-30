# Dynamic Arrays in C

Finally, I have done it

## Usage

```c
#include <stdio.h>
#include "dynamic.h"

createDynamicArray(float, FloatVec); // Must be done in global scope (creates types and functions)


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
```


## How It Works
```c
createDynamicArray(float, FloatVec); 
``` 
Becomes
```c
typedef struct {
  float * data;
  int len;
  int cap;
}
FloatVec;
FloatVec FloatVecNew() {
  FloatVec d;
  d.len = 0;
  d.cap = 1;
  d.data = (float * ) malloc(sizeof(float) * d.cap);
  return d;
}
void FloatVecAppend(FloatVec * d, float val) {
  if (d -> len == d -> cap) {
    d -> cap *= 2;
    d -> data = (float * ) realloc(d -> data, sizeof(float) * d -> cap);
  }
  d -> data[d -> len] = val;
  d -> len++;
}
void FloatVecDestroy(FloatVec * d) {
  free(d -> data);
  d -> len = 0;
  d -> cap = 0;
}
void FloatVecClear(FloatVec * d) {
  d -> len = 0;
}
int FloatVecLen(FloatVec * d) {
  return d -> len;
}
float FloatVecGet(FloatVec * d, int i) {
  if (i <= d -> len) {
    return d -> data[i];
  } else {
    return d -> data[0];
  }
}
void FloatVecSet(FloatVec * d, int i, float val) {
  if (i <= d -> len) {
    d -> data[i] = val;
  }
}
void FloatVecRemove(FloatVec * d, int i) {
  if (i <= d -> len) {
    for (int j = i; j < d -> len - 1; j++) {
      d -> data[j] = d -> data[j + 1];
    }
    d -> len--;
  }
}
```