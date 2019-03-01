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

int countPrimes(int n) {
    int prime[n];
    bzero(prime, sizeof(prime));
	for (int i = 2; i < n; i++) {
		if (!prime[i]){
            prime[0]++; //count prime
            prime[prime[0]] = i;// set n-th prime into n-th postion of array
        }
		for (int j = 1; j <= prime[0] && prime[j] <= n / i; j++) {
            if (prime[j] * i < n){
                prime[prime[j] * i] = 1;
            }
			if (i % prime[j] == 0) break;
		}
	}
    return prime[0];
    /**
     * for (int i = 2; i < n; i++){
     *     nums.push_back(i);
     * }
     * size_t limit = nums.size() / 2;
     * for (size_t i = 0; i < limit; i++){
     *     if (nums[i] == 0){
     *         continue;
     *     }
     *     for (size_t j = i + 1; j < nums.size(); j++){
     *         if (nums[j] && (nums[j] % nums[i] == 0)){
     *             nums[j] = 0;
     *         }
     *     }
     * }
     * int ans = 0;
     * for (int i : nums){
     *     if (i != 0){
     *         ans++;
     *     }
     * }
     * return ans;
     */
}

bool isPowerOfThree(int n) {
    if (n == 0){
        return false;
    }
    while (n != 1){
        if (n % 3 != 0){
            return false;
        }
        n = n / 3;
    }
    return true;
}

/**
 * 另一种方式是不使用迭代和递归的方式
 */ 
bool isPowerOfThree_adv(int n){
    return true;
}

int romanToInt(string s) {
    if (s.empty()){
        return 0;
    }
    int ans = 0;
    size_t ptr = 0;
    while (ptr != s.size()){
        switch (s[ptr])
        {
            case 'I':
                if (s[ptr + 1] == 'V'){
                    ans += 4;
                    ptr += 2;
                }else if (s[ptr + 1] == 'X'){
                    ans += 9;
                    ptr += 2;
                }else{
                    ans += 1;
                    ptr++; 
                }
                break;
            case 'V':
                ans += 5;
                ptr++;
                break;
            case 'X':
                if (s[ptr + 1] == 'L'){
                    ans += 40;
                    ptr += 2;
                }else if (s[ptr + 1] == 'C'){
                    ans += 90;
                    ptr += 2;
                }else{
                    ans += 10;
                    ptr++; 
                }
                break;
            case 'L':
                ans += 50;
                ptr++;
                break;
            case 'C':
                if (s[ptr + 1] == 'D'){
                    ans += 400;
                    ptr += 2;
                }else if (s[ptr + 1] == 'M'){
                    ans += 900;
                    ptr += 2;
                }else{
                    ans += 100;
                    ptr++; 
                }
                break;
            case 'D':
                ans += 500;
                ptr++;
                break;
            case 'M':
                ans += 1000;
                ptr++;
                break;
            default:
                return -1;
        }
    }
    return ans;
}