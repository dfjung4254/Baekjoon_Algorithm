#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char matrix[5][5];
//12시부터 시계방향
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int memoWord[5][5][11];

int hasWord(int i, int j, string word){
    // 좌표유효성 및 첫단어 일치 검사 검사
    if(!(i >= 0 && i < 5 && j >= 0 && j < 5)){
        return -1;
    }
    if(memoWord[i][j][word.size()] != 0){
        return memoWord[i][j][word.size()];
    }
    if(word[0] != matrix[i][j]){
        return memoWord[i][j][word.size()] = -1;
    }
    // 첫단어 일치 검사를 통과했는데 남은 단어가 1개이면 모든 단어 찾은것임
    if(word.size() == 1){
        return memoWord[i][j][word.size()] = 1;
    }
    //재귀구현. 현재위치에서 8방향.
    for(int dir = 0; dir < 8; dir++){
        int ny = i + dy[dir];
        int nx = j + dx[dir];
        if(hasWord(ny, nx, word.substr(1)) == 1){
            return 1;
        }
    }
    //8 방향 탐색했는데도 true 가 없으면 갈방향이 없음 false 반환.
    return memoWord[i][j][word.size()] = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        //입력
        int n;
        for(int i = 0; i < 5; i++){
            string iptline;
            cin >> iptline;
            for(int j = 0; j < 5; j++){
                matrix[i][j] = iptline.at(j);
            }
        }
        cin >> n;
        while(n--){
            memset(memoWord, 0, sizeof(memoWord));
            string candidate;
            cin >> candidate;
            string ret = " NO";
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    if(hasWord(i, j, candidate) == 1){
                        ret = " YES";
                    }
                }
            }
            cout << (candidate+ret) << '\n';
        }
    }


    return 0;
}