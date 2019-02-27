#include "sort_and_search.h"
#include "../main.h"
#include "../util.h"

void test_merge(){
    vector<int> num1 = {1,2,3,0,0,0};
    vector<int> num2 = {2,5,6};
    merge(num1, num1.size() - num2.size(), num2, num2.size());
    print_vec(num1);
}

void test_firstBadVersion(){
    cout << firstBadVersion(10) << endl;
    cout << firstBadVersion(5) << endl;
}

int func(){
    test_firstBadVersion();
    return 0;
}
