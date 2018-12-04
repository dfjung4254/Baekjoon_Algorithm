#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m;
int matrix[9][9];
int testMatrix[9][9];
bool visited[9][9];
int ret = 0;
vector<pair<int,int>> virus;

void bfs(){

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            visited[i][j] = false;
        }
    }

    for(auto it = virus.begin(); it != virus.end(); it++){

        queue<pair<int,int>> q;
        q.push(make_pair(it->first, it->second));
        visited[it->first][it->second] = true;
        while(!q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            //left
            if(cur.second != 1 && testMatrix[cur.first][cur.second-1] == 0
            && visited[cur.first][cur.second-1] == false){
                q.push(make_pair(cur.first,cur.second-1));
                visited[cur.first][cur.second-1] = true;
                testMatrix[cur.first][cur.second-1] = 2;
            }
            //right
            if(cur.second != m && testMatrix[cur.first][cur.second+1] == 0
            && visited[cur.first][cur.second+1] == false){
                q.push(make_pair(cur.first,cur.second+1));
                visited[cur.first][cur.second+1] = true;
                testMatrix[cur.first][cur.second+1] = 2;
            }
            //up
            if(cur.first != 1 && testMatrix[cur.first-1][cur.second] == 0
            && visited[cur.first-1][cur.second] == false){
                q.push(make_pair(cur.first-1,cur.second));
                visited[cur.first-1][cur.second] = true;
                testMatrix[cur.first-1][cur.second] = 2;
            }
            //down
            if(cur.first != n && testMatrix[cur.first+1][cur.second] == 0
            && visited[cur.first+1][cur.second] == false){
                q.push(make_pair(cur.first+1,cur.second));
                visited[cur.first+1][cur.second] = true;
                testMatrix[cur.first+1][cur.second] = 2;
            }
        }

    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(testMatrix[i][j] == 0){
                count++;
            }
        }
    }
    if(count > ret){
        ret = count;
    }

}

void makeWalls(){

    for(int i = 1; i <= m*n-2; i++){
        if(matrix[(i%m == 0) ? i/m:i/m+1][(i%m == 0) ? m:i%m] == 0){
            for(int j = i+1; j <= m*n-1; j++){
                if(matrix[(j%m == 0) ? j/m:j/m+1][(j%m == 0) ? m:j%m] == 0){
                    for(int k = j+1; k <= m*n; k++){
                        if(matrix[(k%m == 0) ? k/m:k/m+1][(k%m == 0) ? m:k%m] == 0){
                            for(int a = 1; a <= n; a++){
                                for(int b = 1; b <= m; b++){
                                    testMatrix[a][b] = matrix[a][b];
                                }
                            }
                            testMatrix[(i%m == 0) ? i/m:i/m+1][(i%m == 0) ? m:i%m] = 1;
                            testMatrix[(j%m == 0) ? j/m:j/m+1][(j%m == 0) ? m:j%m] = 1;
                            testMatrix[(k%m == 0) ? k/m:k/m+1][(k%m == 0) ? m:k%m] = 1;

                            bfs();

                        }
                    }
                }
            }
        }
    }

}

int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 2){
                virus.push_back(make_pair(i,j));
            }
        }
    }
    makeWalls();
    cout << ret << endl;
    return 0;
}
