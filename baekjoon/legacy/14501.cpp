#include <iostream>
using namespace std;

int n;
int t[16];
int p[16];
int ret = 0;

void dfs(int today, int sum){

    sum += p[today];

    bool flag = true;
    for(int i = today+t[today]; i <= n; i++){
        if(i + t[i] <= n+1){
            flag = false;
            dfs(i, sum);
        }
    }
    if(flag){
        if(ret < sum){
            ret = sum;
        }
        return;
    }

}

int main(){

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
    }
    for(int i = 1; i <= n; i++){
        if(i + t[i] <= n+1){
            dfs(i, 0);
        }
    }
    cout << ret << endl;

    return 0;
}
