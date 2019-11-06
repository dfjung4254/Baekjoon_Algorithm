#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int n, l, r;
int country[50][50] = {0, };
bool visited[50][50] = {false, };
int mov_count = 0;
queue<pair<int, int>> q;
vector<pair<int, int>> visiting;
/* up / right / down / left */
const int dir_i[4] = {-1, 0, 1, 0};
const int dir_j[4] = {0, 1, 0, -1};

bool bfs(int init_i, int init_j){

    int sum = 0;
    bool isMoved = false;
    visiting.clear();

    q.push(make_pair(init_i, init_j));
    visited[init_i][init_j] = true;
    while(!q.empty()){
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        visiting.push_back(q.front());
        sum += country[cur_i][cur_j];
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            /* 4방향 탐색 */
            int tar_i = cur_i + dir_i[dir];
            int tar_j = cur_j + dir_j[dir];
            /* 범위 체크 */
            if(tar_i < 0 || tar_i >= n || tar_j < 0 || tar_j >= n || visited[tar_i][tar_j]){
                continue;
            }
            /* 인구 비교 */
            int diff = abs(country[cur_i][cur_j] - country[tar_i][tar_j]);
            bool isUnion = (diff >= l && diff <= r);
            if(isUnion){
                isMoved = true;
                q.push(make_pair(tar_i, tar_j));
                visited[tar_i][tar_j] = true;
            }
        }
    }

    if(isMoved){
        int offset = sum / visiting.size();
        for(pair<int, int> pa : visiting){
            country[pa.first][pa.second] = offset;
        }
    }

    return isMoved;
}

bool moveCountry(){

    /* visited 초기화 */
    for(int i = 0; i < n; i++){
        memset(visited[i], false, sizeof(bool) * n);
    }

    bool moved = false;

    /* 각 배열을 돌면서 bfs 돌린다 */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                if(bfs(i, j)){
                    moved = true;
                }
            }
        }
    }

    return moved;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> country[i][j];
        }
    }

    while(moveCountry()){
        mov_count++;
    }

    cout << mov_count << '\n';

    return 0;
}