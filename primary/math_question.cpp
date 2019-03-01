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
}