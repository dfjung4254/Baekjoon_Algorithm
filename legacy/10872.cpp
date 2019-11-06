#include <iostream>
#define MAX 10000
#define ll unsigned long long
using namespace std;

ll memo[MAX];

ll fib(ll num){

    if(num == 0){
        return 1;
    }

    if(memo[num] != -1){
        return memo[num];
    }

    return memo[num] = num * fib(num - 1);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < MAX; i++){
        memo[i] = -1;
    }
        cout << fib(n) << '\n';

    return 0;
}