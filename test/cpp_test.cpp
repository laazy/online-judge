#include "cpp_test.h"

struct test_class{
    int i;
    bool operator<(const test_class &a) const{
        return a.i < i;
    }
    test_class(int t){
        i = t;
    }
};

void priority_queue_test(){
    std::priority_queue<test_class> test_p_queue;
    test_p_queue.push(test_class(1));
    test_p_queue.push(test_class(5));
    test_p_queue.push(test_class(4));
    test_p_queue.push(test_class(87));
    test_p_queue.push(test_class(3));
    test_p_queue.push(test_class(8));
    test_p_queue.push(test_class(4));
    test_p_queue.push(test_class(0));
    while (!test_p_queue.empty()){
        cout << test_p_queue.top().i << endl;
        test_p_queue.pop();
    }
}
