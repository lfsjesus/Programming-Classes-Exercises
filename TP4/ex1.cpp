#include <iostream>
#include "alist.cpp"
using namespace std;

void append(alist* a, const alist* b) {
    
    int dim_a = a->size, dim_b = b-> size;
    int* c = new int [dim_a + dim_b];

    for (int i = 0; i < dim_a; i++) {
        c[i] = a->elements[i];
    }

    for (int i = 0; i < dim_b; i++) {
        c[dim_a + i] = b->elements[i];
    }

    delete[] a->elements;
    a->size = dim_a + dim_b;
    a->elements = c;

}

int main() {
    alist* a = empty();
    const int nB = 2;
    int eB[nB] = { 1, 2 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
}