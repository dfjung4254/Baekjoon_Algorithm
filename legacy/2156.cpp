#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[10001][3];
int cost[10001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> cost[i];
    }

    for (int i = 1; i <= n; i++){
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        dp[i][1] = dp[i - 1][2] + cost[i];
        dp[i][2] = dp[i - 1][0] + cost[i];
    }

    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]);

    return 0;
}