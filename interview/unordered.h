#ifndef UNORDERED_H
#define UNORDERED_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Couple{
    public:
        bool find_couple(vector<vector<int>> nums);

    private:
        vector<int> elements;
};

int smallest_element(vector<int> &A);

int int_time_string(int D, string &S);

int vacation_time(int Y, string &A, string &B, string &W);

#endif
