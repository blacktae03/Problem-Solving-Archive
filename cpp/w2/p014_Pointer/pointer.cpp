#include "pointer.h"

void update(int * a, int * b) {
    int tmp = *a;
    *a += *b;
    *b = tmp - *b;
}