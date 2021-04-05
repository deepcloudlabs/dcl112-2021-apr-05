#include <iostream>

// 1. call-by-value
/*
void swap(int x,int y){ // Stack: x,y
    int t = x; // Stack
    x = y;
    y = t;
}
 */
// 2. call-by-pointer
void swap(int *x,int *y){ // Stack: x -> u,y -> v
    int t = *x; // Stack
    *x = *y;
    *y = t;
}
// 3. call-by-reference
void swap(int& x,int& y){ // Stack: x,y
    int t = x; // Stack
    x = y;
    y = t;
}

int main(){
    int u = 3, v = 5; // Stack: u=3, v=5
    swap(u,v); // Stack: x->u, y->v
    std::cout << "u: " << u << std::endl; // 3
    std::cout << "v: " << v << std::endl; // 5
}
