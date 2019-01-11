#include <iostream>
using namespace std;

int n;
int sets[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if(n == 0){
        cout << 1 << '\n';
        return 0;
    }
    while(n){
        int tar = n % 10;
        n /= 10;
        sets[tar]++;
    }
    sets[6] = ((sets[6]+sets[9])%2 == 0) ? (sets[6]+sets[9])/2:(sets[6]+sets[9])/2+1;
    int ret = 0;
    for(int i = 0; i < 9; i++){
        if(ret < sets[i]){
            ret = sets[i];
        }
    }
    cout << ret << '\n';

    return 0;
}