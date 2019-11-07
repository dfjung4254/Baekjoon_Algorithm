#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int a, b;
        cin >> a >> b;
        int ans = a;
        for (int i = 1; i < b; i++){
            ans *= a;
            ans %= 10;
        }
        if(ans == 0){
            ans = 10;
        }
        cout << ans << '\n';
    }

    return 0;
}