#include <iostream>

int main() {
    int x = 0;
    int y = 42;
    auto fun = [&x,y](int i) {
        x++;
        return i*i + y;
    };
    fun(42);

    auto max = [](int x,int y) -> int {
        return x>=y ? x : y;
    };
    int a = 10;
    int b = 20;
    std::cout << max(a,b) << std::endl;
    struct smax {
        int operator()(int x,int y){
            return x>=y ? x : y;
        }
    };

}

