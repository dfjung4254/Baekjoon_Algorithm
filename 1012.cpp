#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Farm{

public:
    int n = 0;
    int m = 0;
    int num = 0;
    int matrix[50][50] = {0,};
    bool visited[50][50] = {false, };
    void setFarm(){
        cin >> m >> n >> num;
        for(int i = 0; i < num; i++){
            int x, y;
            cin >> x >> y;
            matrix[y][x] = 1;
        }
    }
    int check(){
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(matrix[i][j]==1 && visited[i][j]==false){
                    count++;
                    queue<p air<int, int>> q;
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    while(!q.empty()){
                        pair<int,int> cur = q.front();
                        q.pop();

                        //left
                        if(j>=1&&matrix[cur.first][cur.second-1]==1
                        &&visited[cur.first][cur.second-1]==false){
                            q.push(make_pair(cur.first,cur.second-1));
                            visited[cur.first][cur.second-1]=true;
                        }
                        //right
                        if(j<m-1&&matrix[cur.first][cur.second+1]==1
                        &&visited[cur.first][cur.second+1]==false){
                            q.push(make_pair(cur.first,cur.second+1));
                            visited[cur.first][cur.second+1]=true;
                        }
                        //up
                        if(i>=1&&matrix[cur.first-1][cur.second]==1
                        &&visited[cur.first-1][cur.second]==false){
                            q.push(make_pair(cur.first-1,cur.second));
                            visited[cur.first-1][cur.second]=true;
                        }
                        //down
                        if(i<n-1&&matrix[cur.first+1][cur.second]==1
                        &&visited[cur.first+1][cur.second]==false){
                            q.push(make_pair(cur.first+1,cur.second));
                            visited[cur.first+1][cur.second]=true;
                        }
                    }

                }

            }
        }
        return count;
    }
};

int main(){

    int testCase;
    cin >> testCase;
    Farm *myFarm = new Farm[testCase];
    for(int i = 0; i < testCase; i++){
        myFarm[i].setFarm();
    }

    for(int i = 0; i < testCase; i++){
        cout << myFarm[i].check() << endl;
    }
    delete[] myFarm;

    return 0;
}
