#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int n;
int arr[MAX];
int dp[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        int tpNum = arr[i];
        for(int j = 1; j <= n; j++){
            if(dp[j] >= tpNum || dp[j] == 0){
                dp[j] = tpNum;
                break;
            }
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i] == 0){
            break;
        }
        ret++;
    }
    cout << ret << '\n';
    return 0;
}