#include <iostream>
using namespace std;

/* up, right, down, left */
const int dir_i[4] = {-1, 0, 1, 0};
const int dir_j[4] = {0, 1, 0, -1};

int n;
char matrix[51][51];
int ans = 0;

void swap(int i, int j, int ni, int nj){
    char tp = matrix[i][j];
    matrix[i][j] = matrix[ni][nj];
    matrix[ni][nj] = tp;
}

void check(int i, int j){

    /* 행 검사 */
    char saved = matrix[i][1];
    int cnt = 1;
    int mx = cnt;
    for (int k = 2; k <= n; k++){
        if(saved == matrix[i][k]){
            cnt++;
        }else{
            saved = matrix[i][k];
            if(mx < cnt){
                mx = cnt;
            }
            cnt = 1;
        }
    }
    if(mx < cnt){
        mx = cnt;
    }
    if(mx > ans){
        ans = mx;
    }
    
    /* 열 검사 */
    saved = matrix[1][j];
    cnt = 1;
    mx = cnt;
    for (int k = 2; k <= n; k++){
        if(saved == matrix[k][j]){
            cnt++;
        }else{
            saved = matrix[k][j];
            if (mx < cnt)
            {
                mx = cnt;
            }
            cnt = 1;
        }
    }
    if (mx < cnt)
    {
        mx = cnt;
    }
    if(mx > ans){
        ans = mx;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    /*
    
        현재 위치에서 4방향으로 스위치 해보고
        각 스위치 마다 해당 위치의 행과 열의 최대값을 구한다.
    
    */
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            check(i, j);
            for (int dir = 0; dir < 4; dir++){
                int ni = i + dir_i[dir];
                int nj = j + dir_j[dir];
                if(ni > 0 && ni <= n && nj > 0 && nj <= n){
                    swap(i, j, ni, nj);
                    check(i, j);
                    swap(i, j, ni, nj);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}