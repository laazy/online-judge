#include "../main.h"
#include "../util.h"
#include "math_question.h"

void test_fizzBuzz(){
    auto s = fizzBuzz(15);
    for (auto i : s){
        cout << i << endl;
    }
}

void test_countPrimes(){
    cout << countPrimes(10) << endl;
    cout << countPrimes(2) << endl;
}

int func(){
    test_countPrimes();
    return 0;
}