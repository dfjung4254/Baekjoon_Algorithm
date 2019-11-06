#include <iostream>
#define MAX 100001
using namespace std;

int n;
int matrix[MAX];
int sums[MAX];

// 시간복잡도 n^2
void noDp(){
    int ret = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += matrix[j];
            if(ret < sum){
                ret = sum;
            }
        }
    }
    cout << ret << '\n';
}

// 시간복잡도 n
void dp(){
    sums[0] = matrix[0];
    int ret = sums[0];
    for(int i = 1; i < n; i++){
        if(sums[i-1] < 0){
            sums[i] = matrix[i];
        }else{
            sums[i] = sums[i-1] + matrix[i];
        }
        if(ret < sums[i]){
            ret = sums[i];
        }
    }
    cout << ret << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> matrix[i];
    }
    dp();

    return 0;
}