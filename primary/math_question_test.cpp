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

void test_isPowerOfThree(){
    cout << (isPowerOfThree(27) == 1) << endl;
    cout << (isPowerOfThree(0) == 0) << endl;
    cout << (isPowerOfThree(9) == 1) << endl;
    cout << (isPowerOfThree(45) == 0) << endl;
}

void test_isPowerOfThree_adv(){
    cout << (isPowerOfThree_adv(27) == 1) << endl;
    cout << (isPowerOfThree_adv(0) == 0) << endl;
    cout << (isPowerOfThree_adv(9) == 1) << endl;
    cout << (isPowerOfThree_adv(45) == 0) << endl;
}

void test_romanToInt(){
    cout << romanToInt("III") <<endl;
    cout << romanToInt("IV") <<endl;
    cout << romanToInt("IX") <<endl;
    cout << romanToInt("LVIII") <<endl;
    cout << romanToInt("MCMXCIV") <<endl;
}

int func(){
    test_romanToInt();
    return 0;
}