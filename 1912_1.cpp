#include <iostream>
using namespace std;

int n;
int num[100001];
int dp[100001];

void dynamicProgramming(){
    for(int i = 1; i <= n; i++){

        if(dp[i-1] + num[i] > num[i]){
            dp[i] = dp[i-1] + num[i];
        }else{
            dp[i] = num[i];
        }
    }
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    dynamicProgramming();
    int max = -1001;
    for(int i = 1; i <= n; i++){
        if(max < dp[i]){
            max = dp[i];
        }
    }
    cout << max << endl;

    return 0;
}
