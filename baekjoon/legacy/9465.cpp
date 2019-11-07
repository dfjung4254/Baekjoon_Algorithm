#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001][3];
int cost[100001][2];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> cost[i][0];
        }
        for (int i = 1; i <= n; i++){
            cin >> cost[i][1];
        }
        for (int i = 1; i <= n; i++){
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + cost[i][0];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + cost[i][1];
        }
        cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
    }

    return 0;
}