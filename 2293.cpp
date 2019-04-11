#include <iostream>
using namespace std;

int n, k;
int dp[10001];
int coin[101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> coin[i];
    }

    dp[0] = 1;

    for (int coinIdx = 1; coinIdx <= n; coinIdx++){
        for (int j = coin[coinIdx]; j <= k; j++){
            dp[j] += dp[j - coin[coinIdx]];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}