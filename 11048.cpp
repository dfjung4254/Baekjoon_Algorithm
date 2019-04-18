#include <iostream>
using namespace std;

int n, m;
int dp[1001][1001];
int matrix[1001][1001];
const int dir_i[3] = {0, -1, -1};
const int dir_j[3] = {-1, -1, 0};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int _max = 0;
            for (int dir = 0; dir < 3; dir++)
            {
                int ni = i + dir_i[dir];
                int nj = j + dir_j[dir];
                if (ni > 0 && nj > 0 && _max < dp[ni][nj])
                {
                    _max = dp[ni][nj];
                }
            }
            dp[i][j] = _max + matrix[i][j];
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}