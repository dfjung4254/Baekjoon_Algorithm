#include <iostream>
using namespace std;

const int dir_i[4] = {-1, 0, 1, 0};
const int dir_j[4] = {0, 1, 0, -1};

int m, n;
int matrix[501][501];
int dp[501][501];
int ans = 0;

int dfs(int ci, int cj){

    if(ci == n && cj == m){
        return 1;
    }else if(dp[ci][cj] != -1){
        return dp[ci][cj];
    }else{
        int ret = 0;
        for (int dir = 0; dir < 4; dir++)
        {
            int ni = ci + dir_i[dir];
            int nj = cj + dir_j[dir];
            if (ni > 0 && ni <= n && nj > 0 && nj <= m && matrix[ci][cj] > matrix[ni][nj])
            {
                ret += dp[ni][nj] = dfs(ni, nj);
            }
        }
        return ret;
    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> matrix[i][j];
            dp[i][j] = -1;
        }
    }

    ans = dfs(1, 1);
    cout << ans << '\n';

    return 0;
}