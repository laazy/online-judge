#ifndef UNORDERED_H
#define UNORDERED_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
class Couple{
    public:
        bool find_couple(vector<vector<int>> nums);

    private:
        vector<int> elements;
        vector<vector<int>> ele_set;
};

#endif
