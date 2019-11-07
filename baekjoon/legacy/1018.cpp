#include <iostream>
using namespace std;

int n, m;
char matrix[51][51];
int ans = 987654321;

int check(int iN, int iM){

    int flag = (iN + iM) % 2;
    char base = matrix[iN][iM];

    int ret = 0;

    for (int i = iN; i <= iN + 7; i++){
        for (int j = iM; j <= iM + 7; j++){
            if (((i + j) % 2 == flag && matrix[i][j] != base) ||
                ((i + j) % 2 != flag && matrix[i][j] == base))
            {
                ret++;
            }
        }
    }

    ret = (ret < 64 - ret) ? ret : 64 - ret;

    return ret;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i <= n - 7; i++){
        for (int j = 1; j <= m - 7; j++){
            int tp = check(i, j);
            if(ans > tp){
                ans = tp;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}