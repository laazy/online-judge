#include "threadtt.h"
#include <thread>
#include <atomic>
#include <condition_variable>
#include <future>
#include <mutex>

const int N = 10000;
uint64_t num {0};
mutex m;

void hello(){
    cout << "hello, world" << endl;
}

void increase(){
    for (int i = 0; i < N; ++i){
        // m.lock();
        ++num;
        // m.unlock();
    }
}

void test_main(){
    clock_t start = clock();
    thread t1(increase);
    t1.join();
    thread t2(increase);
    cout << t2.get_id() << endl;
    thread t3(move(t2));
    cout << t2.get_id() << endl;
    cout << t3.get_id() << endl;
    t3.join();
    clock_t end = clock();
    cout << "time use: " << end - start << endl;
}