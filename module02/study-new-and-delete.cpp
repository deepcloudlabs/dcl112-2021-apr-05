#include <iostream>

int main(){
    int *p; // Stack: p -> ?
    int x = 42; // Stack: x=42
    p = &x; // p -> x

    int *q; // Stack: q -> ?

    // Heap: [4 8 15 16 23 42 ]
    q = new int[6]{4,8,15,16,23,42}; // q -> [ 4 ]
    int * r = q + 1; // r -> [8]
    // pointer arithmetic
    r = q + 5; // r = q + 5 * sizeof(int) r -> [ 42 ]
    std::cout << *r << std::endl; // 42

    // Wrong: delete q; // Memory Leak: q -> [ 4 ] -> Out of Memory Error
    delete []q; // new int[]{4,8,15,16,23,42}
    // Wrong: delete []r; // Crash!!!
}

