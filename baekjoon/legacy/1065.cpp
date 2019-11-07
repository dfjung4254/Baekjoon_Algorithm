#include <iostream>
using namespace std;

int n;
int dp[1001];

int main(){

    cin >> n;

    for(int i = 1; i <= n; i++){

        int a, b, c, d;
        a = i/1000;
        b = i/100 - a*10;
        c = i/10 - a*100 - b*10;
        d = i - a*1000 - b*100 - c*10;

        if(a==0&&b==0&&c==0){
            dp[i] = dp[i-1]+1;
        }else if(a==0&&b==0){
            dp[i] = dp[i-1]+1;
        }else if(a==0&&b-c == c-d){
            dp[i] = dp[i-1]+1;
        }else{
            dp[i] = dp[i-1];
        }

//        cout << a << b << c << d << " " << dp[i] << endl;

    }
    cout << dp[n] << endl;

    return 0;
}
