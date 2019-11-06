#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[501][501];
int cost[501][501];
int ans = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + cost[i][j];
            if(i == n && dp[i][j] > ans){
                ans = dp[i][j];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}