#include <iostream>

using namespace std;

int matrix[10][10];
int paperCnt[6] = {0, 5, 5, 5, 5, 5};
int ans = 987654321;
int cnt = 0;

bool checkArea(int size, int dir_i, int dir_j){
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int cur_i = dir_i + i;
            int cur_j = dir_j + j;
            if(cur_i >= 10 || cur_j >= 10 || matrix[cur_i][cur_j] == 0){
                return false;
            }
        }
    }

    return true;
}

void pasteArea(int size, int dir_i, int dir_j, bool isPaste){

    int val = (isPaste) ? 0 : 1;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int cur_i = dir_i + i;
            int cur_j = dir_j + j;
            matrix[cur_i][cur_j] = val;
        }
    }
}

void check(int _i, int _j){

    if(_i >= 10){
        if(ans > cnt){
            ans = cnt;
        }
        return;
    }

    if(_j >= 10){
        check(_i + 1, 0);
        return;
    }

    if(matrix[_i][_j] == 0){
        check(_i, _j + 1);
        return;
    }

    for(int pSize = 5; pSize > 0; pSize--){
        if(checkArea(pSize, _i, _j) && paperCnt[pSize] > 0){

            pasteArea(pSize, _i, _j, true);
            cnt++;
            paperCnt[pSize]--;

            check(_i, _j + 1);

            pasteArea(pSize, _i, _j, false);
            cnt--;
            paperCnt[pSize]++;

        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> matrix[i][j];
        }
    }

    /* dfs 로 접근, 재귀적으로 접근한다. */
    check(0, 0);    
    ans = (ans == 987654321) ? -1 : ans;
    cout << ans << '\n';

    return 0;
}