#include <iostream>
using namespace std;

int dp[30][30];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 30; i++){
        dp[0][i] = 1;
    }

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
        }

        cout << dp[n][m] << '\n';
    }

    return 0;
}