#include <iostream>
using namespace std;

int n, m;
int dp[301][301] = {0, };

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        dp[1][i] = i - 1;
    }

    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j] + j;
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}