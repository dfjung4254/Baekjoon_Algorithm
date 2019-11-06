#include <iostream>
using namespace std;

int n;
int matrix[301] = {0, };
int retMax = 0;
int memo[301] = {0, };

void dp(int cur, int sum, int stack){
    sum += matrix[cur];

    if(memo[cur] == 0 || memo[cur] < sum){
        memo[cur] = sum;
    }else{
        return;
    }

    if(cur == n){
        if(retMax < sum){
            retMax = sum;
        }
        return;
    }
    if(stack != 2){
        //�Ѱ���
        dp(cur+1, sum, stack+1);
    }
    if(cur != n-1){
        //�ΰ���
        dp(cur+2, sum, 1);
    }

}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> matrix[i];
    }
    dp(0, 0, 0);
    // for(int i = 1; i <= n; i++){
    //     cout << memo[i] << " ";
    // }
    // cout << endl;
    cout << retMax << endl;
    return 0;
}
