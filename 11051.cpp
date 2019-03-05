#include <iostream>
#include <string.h>
#define MOD 10007
using namespace std;

int n, r;
int memo[1001][1001];
int comb(int n, int r){
    if(r == 0){
        return 1;
    }else if(r == 1){
        return n;
    }else if(n == r){
        return 1;
    }else{
        if(memo[n-1][r] == -1){
            memo[n-1][r] = comb(n-1, r);
        }
        if(memo[n-1][r-1] == -1){
            memo[n-1][r-1] = comb(n-1, r-1);
        }
        return (memo[n-1][r] + memo[n-1][r-1]) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(memo, -1, sizeof(memo));
    cin >> n >> r;
    cout << comb(n, r) << '\n';

    return 0;
}