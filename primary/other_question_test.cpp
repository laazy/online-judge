#include "other_question.h"
#include "../main.h"
#include "../util.h"

void test_hammingWeight(){
    cout << hammingWeight(11) << endl;
    cout << hammingWeight(64) << endl;
    cout << hammingWeight(0xfffffffd) << endl;
}

void test_hammingWeight2(){
    cout << hammingWeight2(11) << endl;
    cout << hammingWeight2(64) << endl;
    cout << hammingWeight2(0xfffffffd) << endl;
}

int func(){
    test_hammingWeight();
    test_hammingWeight2();
    return 0;
}
