#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

const string TARGET = "123456789";
map<string, int> visitedMap;
queue<string> q;

/* left, right, up, down */
int dir_i[4] = {-1, 1, 0, 0};
int dir_j[4] = {0, 0, -1, 1};

string swap(string a, int idx1, int idx2){

    char tp = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = tp;
    return a;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input = "";
    for(int i = 0; i < 9; i++){
        string tp;
        cin >> tp;
        if(tp.compare("0") == 0){
            tp = "9";
        }
        input += tp;
    }

    q.push(input);
    visitedMap[input] = 0;

    while(!q.empty()){

        string cur = q.front();
        int curCnt = visitedMap[cur];
        q.pop();

        /* 9 가 있는 인덱스 찾기 */
        int idx = 0;
        while(idx < 9){
            if(cur[idx] == '9'){
                break;
            }
            idx++;
        }

        int idx_i = idx / 3;
        int idx_j = idx % 3;

        /* 인접 4가지 방향을 돈다. */
        for(int dir = 0; dir < 4; dir++){
            int nIdx_i = idx_i + dir_i[dir];
            int nIdx_j = idx_j + dir_j[dir];
            if(nIdx_i < 0 || nIdx_i > 2 || nIdx_j < 0 || nIdx_j > 2 ){
                continue;
            }
            int nextIdx = nIdx_i * 3 + nIdx_j;
            if(nextIdx >= 0 && nextIdx < 9){
                string nextCase = swap(cur, idx, nextIdx);
                if(visitedMap.find(nextCase) == visitedMap.end()){
                    /* 중복하지 않음 */
                    visitedMap[nextCase] = curCnt + 1;
                    q.push(nextCase);
                }
            }
        }

    }

    if(visitedMap.find(TARGET) == visitedMap.end()){
        cout << -1 << '\n';
    }else{
        cout << visitedMap[TARGET] << '\n';
    }

    return 0;
}