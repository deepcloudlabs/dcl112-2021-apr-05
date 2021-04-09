#include <thread>
#include <mutex>
#include <atomic>
#include <iostream>

using namespace std;
// scalability: core numbers
atomic<int> counter(0); // lock-free -> does require thread parking
//int counter{0}; // resource -> memory -> data (global variable)
mutex m;
struct task{ // thread-safe data structure/class
    void operator()(){
        for (auto i=0;i< 500'000;++i){ // critical section
        //m.lock(); // thread parking
            counter++; // atomic<int> -> atomic
        // m.unlock();
        }
    }
};

int main(){ // application -> thread-safety, dead-lock, liveness, ...
    cerr << "counter: " << counter << endl ;
    task task1;
    task task2;
    auto start = chrono::high_resolution_clock::now();
    thread t1(task1);
    thread t2(task2);
    thread t3(task2);
    thread t4(task2);
    thread t5(task2);
    t1.join(); t2.join(); t3.join(); t4.join(); t5.join();
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> dur = stop - start;
    // 9758400 ns vs. 19690102800 ns vs. 5865100 ns. vs. 63859300
                    // 3357 x
    cerr << "counter: " << counter
         << " @ " << (long) dur.count() << " ns."
         << endl ;
    cerr << "done." << endl;
    return 0;
}