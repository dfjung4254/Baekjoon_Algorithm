#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int matrix[101][101];
int visited[101][101];

void bfs(int n, int m){
    int count = 1;
    visited[1][1] = count;
    queue<pair<int, int>> q;
    q.push(make_pair(1,1));

    while(!q.empty()){

        pair<int, int> cur = q.front();
        q.pop();

        //left
        if(cur.second != 1 && visited[cur.first][cur.second-1] == 0
        && matrix[cur.first][cur.second-1] == 1){
            visited[cur.first][cur.second-1] = visited[cur.first][cur.second]+1;
            q.push(make_pair(cur.first, cur.second-1));
        }
        //right
        if(cur.second != m && visited[cur.first][cur.second+1] == 0
        && matrix[cur.first][cur.second+1] == 1){
            visited[cur.first][cur.second+1] = visited[cur.first][cur.second]+1;
            q.push(make_pair(cur.first, cur.second+1));
        }
        //up
        if(cur.first != 1 && visited[cur.first-1][cur.second] == 0
        && matrix[cur.first-1][cur.second] == 1){
            visited[cur.first-1][cur.second] = visited[cur.first][cur.second]+1;
            q.push(make_pair(cur.first-1, cur.second));
        }
        //down
        if(cur.first != n && visited[cur.first+1][cur.second] == 0
        && matrix[cur.first+1][cur.second] == 1){
            visited[cur.first+1][cur.second] = visited[cur.first][cur.second]+1;
            q.push(make_pair(cur.first+1, cur.second));
        }

    }

}

int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string line;
        cin >> line;
        for(int j = 1; j <= m; j++){
            matrix[i][j] = line[j-1]-'0';
        }
    }

    bfs(n, m);
    // cout << '\n';
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << visited[i][j];
    //     }
    //     cout << '\n';
    // }

    // cout << '\n';
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cout << matrix[i][j];
    //     }
    //     cout << '\n';
    // }
    cout << visited[n][m] << endl;

    return 0;
}
