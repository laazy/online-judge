#include "array_question.h"
#include "../main.h"

void print_vec(vector<int> vec){
    for (int i : vec){
        cout << i << " ";
    }
    cout << endl;
}

void test_removeDuplicates(){
    vector<int> vec{1,2,3,3,3,4,5,6,6,7,7,7,8};
    cout << removeDuplicates(vec) << endl;
    print_vec(vec);
}

void test_maxProfit(){
}

void test_rotate(){
    vector<int> vec{1,2,3,3,3,4,5,6,6,7,7,7,8};
    rotate(vec, 2);
    print_vec(vec);
}

void test_containsDuplicate() {
    vector<int> vec1{1,2,3,3,3,4,5,6,6,7,7,7,8};
    vector<int> vec2{1,2,3,4,5,6,7,8,9,0};
    cout << containsDuplicate(vec1) << endl;
    cout << containsDuplicate(vec2) << endl;
}

void test_singleNumber() {
    vector<int> vec1{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,7,8,9,0};
    vector<int> vec2{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,8,9,0};
    vector<int> vec3{2,2,1};
    cout << singleNumber(vec1) << endl;
    cout << singleNumber(vec3) << endl;
}

void test_intersect(){
    vector<int> vec1{1,2,2,1};
    vector<int> vec2{2,2};
    print_vec(intersect(vec1, vec2));
}
void test_plusOne(){
    vector<int> vec1{1,2,2,1};
    vector<int> vec2{1,9,9,9};
    vector<int> vec3{9,9,9};
    print_vec(plusOne(vec1));
    print_vec(plusOne(vec2));
    print_vec(plusOne(vec3));
}

void test_moveZeroes() {
    vector<int> vec1{1,0,0,1,1,1};
    vector<int> vec2{1,9,9,9};
    vector<int> vec3{9,0,9};
    print_vec(plusOne(vec1));
    print_vec(plusOne(vec2));
    print_vec(plusOne(vec3));
}

int func(){
    test_plusOne();
    return 0;
    // return test_removeDuplicates();
}