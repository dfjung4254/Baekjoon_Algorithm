#include <iostream>
using namespace std;

int n, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int up = 1, bottom = 1;
    for(int i = n; i > n-k; i--){
        up *= i;
        bottom *= n-i+1;
    }
    cout << up/bottom << '\n';

    return 0;
}