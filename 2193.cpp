#include <iostream>
using namespace std;

int n;
long long memo[91];

long long fib(int n){
    if(n == 1){
        return memo[n];
    }else if(n == 2){
        return memo[n];
    }else{
        if(memo[n-1] == 0){
            memo[n-1] = fib(n-1);
        }
        if(memo[n-2] == 0){
            memo[n-2] = fib(n-2);
        }
        return memo[n-1] + memo[n-2];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memo[1] = 1;
    memo[2] = 1;
    cout << fib(n) << '\n';

    return 0;
}