#include <iostream>
using namespace std;

int dp[501][501];
int sp[501][501];
int nums[501];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> sp[i][i];
        }
        for (int gap = 1; gap <= n - 1; gap++)
        {
            for (int i = 1; i <= n - gap; i++)
            {
                int j = i + gap;
                int _min = 987654321;
                sp[i][j] = sp[i][j - 1] + sp[j][j];
                for (int k = i; k < j; k++)
                {
                    int num = dp[i][k] + dp[k + 1][j] + sp[i][j];
                    if (num < _min)
                    {
                        _min = num;
                    }
                }
                dp[i][j] = _min;
            }
        }
        cout << dp[1][n] << '\n';
    }

    return 0;
}