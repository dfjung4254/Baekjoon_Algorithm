#include <iostream>
#include <string>
using namespace std;

string a, b;
int dp[1001][1001];
int n, m;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a;
    cin >> b;
    n = a.size();
    m = b.size();

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                int _max = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
                dp[i][j] = _max;
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}