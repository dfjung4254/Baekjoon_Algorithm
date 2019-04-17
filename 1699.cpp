#include <iostream>
using namespace std;

int n;
int dp[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        int _min = 987654321;
        for (int j = 1; j*j <= i; j++){
            if(dp[i - j*j] + 1 < _min){
                _min = dp[i - j * j] + 1;
            }
        }
        dp[i] = _min;
    }

    cout << dp[n] << '\n';

    return 0;
}