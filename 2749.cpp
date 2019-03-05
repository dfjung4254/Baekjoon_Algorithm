#include <iostream>
#define ll long long
#define MOD 1000000
#define PERIOD 1500000
using namespace std;

ll n;
ll memo[PERIOD+1];

ll fib(ll n){
    memo[0] = 0;
    memo[1] = 1;
    for(ll i = 2; i <= n; i++){
        memo[i] = (memo[i-1] + memo[i-2]) % MOD;
    }
    return memo[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll pIdx = n % PERIOD;
    cout << fib(pIdx) << '\n';

    return 0;
}