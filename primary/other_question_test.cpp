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

void test_generate(){
    print_matrix(generate(5));
}

void test_isValid(){
    cout << (isValid("()") == 1) << endl;
    cout << (isValid("[") == 0) << endl;
    cout << (isValid("]") == 0) << endl;
    cout << (isValid("()[]{}") == 1) << endl;
    cout << (isValid("(]") == 0) << endl;
    cout << (isValid("([)]") == 0) << endl;
    cout << (isValid("{[]}") == 1) << endl;
}

void test_missingNumber(){
    cout << (missingNumber({3,0,1}) == 2) << endl;
    cout << (missingNumber({9,6,4,2,3,5,7,0,1}) == 8) << endl;
}

int func(){
    test_missingNumber();
    return 0;
}
