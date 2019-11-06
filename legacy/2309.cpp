#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[10];
int v[8];

void dfs(int n, int r, int index, int i){

    if(index == r+1){
        int sum = 0;
        for(int i = 1; i <= r; i++){
            sum += v[i];
        }
        if(sum == 100){
            sort(v, v+8);
            for(int i = 1; i <= r; i++){
                cout << v[i] << '\n';
            }
        }
        return;
    }

    if(i >= n+1){
        return;
    }

    v[index] = num[i];
    dfs(n,r,index+1,i+1);
    dfs(n,r,index,i+1);

}

int main(){

    for(int i = 1; i <= 9; i++){
        cin >> num[i];
    }
    dfs(9, 7, 1, 1);

    return 0;
}
