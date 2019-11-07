#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[25][25];
bool visited[25][25];
vector<int> area;

void bfs(int i, int j, int maxSize, int &count){

    queue<pair<int, int>> q;
    q.push(make_pair(i,j));
    visited[i][j] = true;

    while(!q.empty()){
        //right
        pair<int, int> cur = q.front();
        q.pop();
        if(cur.second != maxSize-1 && visited[cur.first][cur.second+1] == false
        && matrix[cur.first][cur.second+1] == 1){
            //오른쪽 끝 아님
            count++;
            q.push(make_pair(cur.first, cur.second+1));
            visited[cur.first][cur.second+1] = true;
        }
        //left
        if(cur.second != 0 && visited[cur.first][cur.second-1] == false
        && matrix[cur.first][cur.second-1] == 1){
            count++;
            q.push(make_pair(cur.first, cur.second-1));
            visited[cur.first][cur.second-1] = true;
        }
        //up
        if(cur.first != 0 && visited[cur.first-1][cur.second] == false
        && matrix[cur.first-1][cur.second] == 1){
            count++;
            q.push(make_pair(cur.first-1, cur.second));
            visited[cur.first-1][cur.second] = true;
        }
        //down
        if(cur.first != maxSize-1 && visited[cur.first+1][cur.second] == false
        && matrix[cur.first+1][cur.second]){
            count++;
            q.push(make_pair(cur.first+1, cur.second));
            visited[cur.first+1][cur.second] = true;
        }
    }


}

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < n; j++){
            matrix[i][j] = line[j] - '0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1 && visited[i][j] == false){
                area.push_back(1);
                bfs(i, j, n, area.back());
            }
        }
    }

    sort(area.begin(), area.end());

    cout << area.size() << endl;
    for(auto it = area.begin(); it != area.end(); it++){
        cout << *it << '\n';
    }

    return 0;
}
