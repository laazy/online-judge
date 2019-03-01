#include "../main.h"
#include "../util.h"
#include "math_question.h"

void test_fizzBuzz(){
    auto s = fizzBuzz(15);
    for (auto i : s){
        cout << i << endl;
    }
}

int func(){
    test_fizzBuzz();
    return 0;
}