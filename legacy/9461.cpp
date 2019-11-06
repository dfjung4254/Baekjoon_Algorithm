#include <iostream>
#define ll unsigned long long
using namespace std;

ll dp[101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 6; i <= 100; i++){
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}