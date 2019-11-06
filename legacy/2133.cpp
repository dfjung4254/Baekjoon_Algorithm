#include <iostream>
using namespace std;

int n;
int dp[31][3];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    for (int i = 4; i <= n; i+=2){
        dp[i][0] = dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2];
        dp[i][1] = dp[i - 2][0] + dp[i - 2][1] * 2 + dp[i - 2][2];
        dp[i][2] = dp[i - 2][0] + dp[i - 2][1] + dp[i - 2][2] * 2;
    }

    int ans = dp[n][0] + dp[n][1] + dp[n][2];
    cout << ans << '\n';

    return 0;
}