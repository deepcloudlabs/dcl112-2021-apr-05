#include <iostream>

template <typename T>
void printArray(const T *a,const int size){
    for (int i=0;i < size;i++)
        std::cout << a[i] << ":" ;
    std::cout << std::endl ;
}

void printArray(const int *a,const int size){
    for (int i=0;i < size;i++)
        std::cout << a[i] << "," ;
    std::cout << std::endl ;
}

int main(){
    int a[3] {1,2,3};
    double b[3] {10.1,22.4,33.5};
    printArray(a, 3); // specific implementation -> line 8
    printArray(b, 3); // template
    return 0;
}

