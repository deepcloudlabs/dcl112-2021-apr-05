#include <iostream>

int main(){
    int x = 42; // Stack
    int& y= x;  // x, y
    x++; // x = 43
    y++; // x = 44
    double numbers[]{4,8,15,16,23,42}; // Stack
    double& firstNumber = numbers[0];
    double &lastNumber = numbers[5];
    firstNumber++; // numbers[0]++
    lastNumber--; // numbers[5]--
    std::cout << "firstNumber: " << firstNumber << std::endl;
    std::cout << "lastNumber: " << lastNumber << std::endl;
    return 0;
}


