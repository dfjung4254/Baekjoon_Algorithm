#include <iostream>
using namespace std;

const char ans[5] = {'E', 'A', 'B', 'C', 'D'};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 3; i++){
        int cnt = 0;
        for (int j = 0; j < 4; j++){
            int n;
            cin >> n;
            if(n == 0){
                cnt++;
            }
        }
        cout << ans[cnt] << '\n';
    }

        return 0;
}