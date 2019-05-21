#include <iostream>
#define MOD 1000000000
using namespace std;

int dp[101][10] = {
    0,
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 100; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int upper = j + 1;
            int down = j - 1;
            if (upper < 10)
            {
                dp[i][j] += dp[i - 1][upper];
                dp[i][j] %= MOD;
            }
            if (down >= 0)
            {
                dp[i][j] += dp[i - 1][down];
                dp[i][j] %= MOD;
            }
        }
    }

    int tc;
    cin >> tc;
    int tCase = 1;
    while (tc--)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            ans += dp[n][i];
        }

        cout << "#" << tCase++ << " " << ans << '\n';
    }

    return 0;
}