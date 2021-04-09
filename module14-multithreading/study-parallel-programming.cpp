#include <thread>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <future>

using namespace std;

// const int SIZE = 100'000'000; // 2.57
// const int SIZE = 200'000'000; // 2.97
const int SIZE = 300'000'000; // 3.41


int numbers[SIZE]; // DATA
template<typename iter>
void init(iter beg, iter end, int value) {
    for (iter p = beg; p != end; ++p) {
        *p = value;
    }
}

template<typename iter>
int partial_sum(iter beg, iter end) {
    return accumulate(beg, end, int());
}

int main() {
    auto cpus = thread::hardware_concurrency();
    cout << "cpus: " << cpus << endl;
    init(numbers, numbers + SIZE, 1);
    auto t1 = chrono::high_resolution_clock::now();
    auto sumSerial = accumulate(numbers, numbers + SIZE, int());
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> dur_serial = t2 - t1;
    cout << "Sum: " << sumSerial
         << " @ " << (int) dur_serial.count() << " ns."
         << endl;
    // partitioning
    int size_per_thread = SIZE / cpus;
    auto begin = numbers;
    auto end = begin + size_per_thread;
    vector<future<int>> futures;
    auto t3 = chrono::high_resolution_clock::now();
    for (auto i = 0; i < cpus; ++i) {
        futures.push_back(async(partial_sum<int*>,begin,end));
        begin += size_per_thread;
        end += size_per_thread;
    }
    auto sumParallel = 0;
    for (auto &ft : futures){
        sumParallel += ft.get();
    }
    auto t4 = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> dur_parallel = t4 - t3;
    cout << "Sum: " << sumParallel
         << " @ " << (int) dur_parallel.count() << " ns."
         << endl;
    return 0;
}

