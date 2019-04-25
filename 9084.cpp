#include <iostream>
#include <string.h>
using namespace std;

int dp[10001];
int coins[21];
int target;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        for (int i = 0; i < 21; i++){
            coins[i] = 0;
        }
        for (int i = 0; i < 10001; i++)
        {
            dp[i] = 0;
        }
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> coins[i];
        }
        cin >> target;
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            for(int j = coins[i]; j <= target; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        cout << dp[target] << '\n';
    }

    return 0;
}