#include "test.h"
#include "../main.h"
#include <iostream>

using namespace std;

int test_hello() {
    printf("hello, world\n");
    return 0;
}


class test{
    public:
        int data;
        test(int data){
            this->data = data;
            cout << "test1" << this << endl;
        }

        test(test&& t){
            this->data = 1;
            cout << "test2" << endl;
        }
        test & operator=(test && t){
            this->data = t.data;
            cout << "op=" << endl;
            return *this;
        }
};

test func2(int data){
    return test(data);
}

int func(){
    // test t(1);
    test b(10);
    test t = test((func2(2)));
    cout << t.data << endl;
    return 0;
}
