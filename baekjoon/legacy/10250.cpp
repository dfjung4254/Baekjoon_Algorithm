#include <iostream>
#define MAX 100
using namespace std;

int matrix[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n, m, targ;
        cin >> n >> m >> targ;
        int cnt = 0;
        bool flag = false;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(++cnt == targ){
                    cout << j;
                    if(i/10 == 0){
                        cout << 0;
                    }
                    cout << i << '\n';
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
    }


    return 0;
}