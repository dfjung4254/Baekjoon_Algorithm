#include <iostream>
using namespace std;

int n;
long long memo[46];

long long fib(int num){
    if(num == 0){
        return memo[0];
    }else if(num == 1){
        return memo[1];
    }else{
        if(memo[num-1] == 0){
            memo[num-1] = fib(num-1);
        }
        if(memo[num-2] == 0){
            memo[num-2] = fib(num-2);
        }
        return memo[num-1] + memo[num-2];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memo[0] = 0;
    memo[1] = 1;
    cout << fib(n) << '\n';

    return 0;
}