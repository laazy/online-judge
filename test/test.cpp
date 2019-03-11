#include "test.h"
#include "../main.h"
#include <iostream>

using namespace std;

int test_hello() {
    printf("hello, world\n");
    return 0;
}

int func(){
    test_hello();
    return 0;
}
