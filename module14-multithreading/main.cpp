#include <iostream>
#include <thread>

int data = 42; // data -> shared memory: data + text (task1) + heap
int *p = new int(42); // p-> heap (42)

void task1(){
    std::cerr << "Running task #1" << std::endl;
    data++; // data
    (*p)++; // heap
}

struct task2 { // functor
    void operator()(){
        std::cerr << "Running task #2" << std::endl;
        data++; // data
        (*p)++; // heap
    }
};

int main() {
    std::thread t1(task1); // t1, process
    task2 fun;
    std::thread t2(fun); // t2, process
    std::thread t3{fun}; // t3, process
    std::thread t4([](){
        std::cerr << "Running lambda expression..." << std::endl;
        data++; // data
        (*p)++; // heap
    }); // t4, process

    std::cerr << "main:: data: " << data << std::endl;
    std::cerr << "main:: heap: " << *p << std::endl;
    // synchronization
    t1.join();
    std::cerr << "t1 is done." << std::endl;
    t2.join();
    std::cerr << "t2 is done." << std::endl;
    t3.join();
    std::cerr << "t3 is done." << std::endl;
    t4.join();
    std::cerr << "t4 is done." << std::endl;
    std::cerr << "main:: data: " << data << std::endl;
    std::cerr << "main:: heap: " << *p << std::endl;
    return 0;
}
