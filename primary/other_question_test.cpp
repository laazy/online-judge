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

void test_hammingDistance(){
    cout << hammingDistance(1, 4) << endl;
}

void test_reverseBits(){
    cout << (reverseBits(43261596) == 964176192) << endl;
    cout << (reverseBits(4294967293) == 3221225471) << endl;
}

int func(){
    test_reverseBits();
    return 0;
}
