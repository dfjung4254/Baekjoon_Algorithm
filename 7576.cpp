#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int retCount;
vector<pair<int, int>> init;
int matrix[1001][1001];
int visited[1001][1001];

void bfs(vector<pair<int, int>> start){
    queue<pair<int, int>> q;
    for(auto it = start.begin(); it != start.end(); it++){
        q.push(*it);
        visited[it->first][it->second] = 0;
    }
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        //right
        if(cur.second != m && matrix[cur.first][cur.second+1] == 0
        && visited[cur.first][cur.second+1] == 0){
            q.push(make_pair(cur.first,cur.second+1));
            visited[cur.first][cur.second+1] = visited[cur.first][cur.second]+1;
        }
        //left
        if(cur.second != 1 && matrix[cur.first][cur.second-1] == 0
        && visited[cur.first][cur.second-1] == 0){
            q.push(make_pair(cur.first,cur.second-1));
            visited[cur.first][cur.second-1] = visited[cur.first][cur.second]+1;
        }
        //top
        if(cur.first != 1 && matrix[cur.first-1][cur.second] == 0
        && visited[cur.first-1][cur.second] == 0){
            q.push(make_pair(cur.first-1,cur.second));
            visited[cur.first-1][cur.second] = visited[cur.first][cur.second]+1;
        }
        //bottom
        if(cur.first != n && matrix[cur.first+1][cur.second] == 0
        && visited[cur.first+1][cur.second] == 0){
            q.push(make_pair(cur.first+1,cur.second));
            visited[cur.first+1][cur.second] = visited[cur.first][cur.second]+1;
        }
    }

}

int main(){

    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1){
                init.push_back(make_pair(i,j));
            }
        }
    }

    bfs(init);
    bool flag = false;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(visited[i][j] == 0){
                if(matrix[i][j] == 0){
                    retCount = -1;
                    flag = true;
                    break;
                }
            }else if(retCount == 0 || visited[i][j] > retCount){
                retCount = visited[i][j];
            }
        }
        if(flag){
            break;
        }
    }

    cout << retCount << endl;

    return 0;
}
