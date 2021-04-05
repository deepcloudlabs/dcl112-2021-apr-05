#include <iostream>

#define SQ(x) ((x)*(x)) // macro definition

inline int square(int x) { // Text
    // do some processing
    return x * x;
}

int main() {
    int u = 42, v = 108;
    // C: int z = SQ(u+v); // preprocessing -> int z = ((u+v)*(u+v));
    // C++:
    int z = square(u + v); // code -> main -> text -> memory foot-print -> cache
    std::cout << "z: " << z;
    return 0;
}

