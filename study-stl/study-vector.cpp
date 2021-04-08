#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <deque>

struct PrintInteger {
    void operator()(int number){
        std::cout << number << std::endl;
    }
};

int main() {
    std::deque<int> numbers{4, 8, 15, 16, 23, 42};
    std::cout << "size: " << numbers.size() << std::endl;
    numbers.push_back(62); // rear
    std::cout << "size: " << numbers.size() << std::endl;
    // loop #1 - External Loop
    std::cout << "loop #1 while" << std::endl;
    auto iter = numbers.begin();
    while (iter != numbers.end()){
        std::cout << *iter << std::endl;
        iter++;
    }
    // loop #2 - External Loop
    std::cout << "loop #2 classical for" << std::endl;
    for (auto p=numbers.begin(); p!= numbers.end();p++){
        std::cout << *p << std::endl;
    }
    // loop #3 (c++11) (for-each syntax) - External Loop
    std::cout << "loop #3 (c++11)" << std::endl;
    for (auto& number : numbers){
        std::cout << number << std::endl;
    }
    // loop #4 (STL Algorithm) - Internal Loop
    std::cout << "loop #4 (STL Algorithm) - Internal Loop - Functor" << std::endl;
    // functor -> Lambda Expression
    std::for_each(numbers.begin(),numbers.end(),PrintInteger());
    std::cout << "loop #4 (STL Algorithm) - Internal Loop - Lambda Expression" << std::endl;
    std::for_each(numbers.begin(),numbers.end(),[](int number){
        std::cout << number << std::endl;
    });
    return 0;
}
