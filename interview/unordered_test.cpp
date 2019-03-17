#include "unordered.h"
#include "../util.h"
#include "../main.h"

#define null 0

void test_find_couple(){
    vector<vector<int>> nums1 {{2,  1}, 
                           {2,  1},{2,  3},
                       {1,  2},{1,  2},{3,  3}};
    Couple couple = Couple();

    cout << couple.find_couple(nums1) << endl;
}

void test_smallest_element(){
    vector<int> A = {1, 3, 6, 4, 1, 2};
    cout << smallest_element(A) << endl;
    vector<int> A1 = {1,2,3};
    cout << smallest_element(A1) << endl;
    vector<int> A2 = {-1, -3};
    cout << smallest_element(A2) << endl;
}

void test_int_time_string(){
    string s1 = "four";
    cout << int_time_string(4, s1) << endl;
}

void test_vacation_time(){
    string begin = "April", end = "May", first_weekday = "Wednesday";
    cout << vacation_time(2014, begin, end, first_weekday) << endl;
    begin = "October", end = "December", first_weekday = "Monday";
    cout << vacation_time(2018, begin, end, first_weekday) << endl;
}

int func(){
    test_find_couple();
    return 0;
}
