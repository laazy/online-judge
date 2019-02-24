#include "util.h"

void print_vec(const vector<int> &vec){
    for (int i : vec){
        cout << i << " ";
    }
    cout << endl;
}

void print_matrix(const vector<vector<int>> &mat){
    for (auto i : mat){
        print_vec(i);
    }
}

void print_string(const vector<char> &str){
    for (auto i : str){
        cout << i;
    }
    cout << endl;
}
