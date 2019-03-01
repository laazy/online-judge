#include "math_question.h"

vector<string> fizzBuzz(int n) {
    vector<string> ans {""};
    for (int i = 1; i <= n; i++){
        ans.push_back("");
        if (i % 3 == 0){
            ans[i] += "Fizz";
        }
        if (i % 5 == 0){
            ans[i] += "Buzz";
        }
        if (ans[i] == ""){
            ans[i] = to_string(i);
        }
    }
    ans.erase(ans.begin());
    return ans;
}