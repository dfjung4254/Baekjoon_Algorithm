#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n, m;
int matrix[502][502] = {0, };

int find(pair<int, int> cur, int index, int sum, bool visited[502][502]){
    if(index == 5){
        return sum;
    }
    cout << cur.first << " / " << cur.second << " ¹æ¹®" << '\n';
    sum += matrix[cur.first][cur.second];
    visited[cur.first][cur.second] = true;
    //Å½»ö
    int max = 0;
    pair<int, int> next;
    //up
    if(matrix[cur.first-1][cur.second] > max
    &&visited[cur.first-1][cur.second] == false){
        max = matrix[cur.first-1][cur.second];
        next = make_pair(cur.first-1, cur.second);
    }
    //down
    if(matrix[cur.first+1][cur.second] > max
    &&visited[cur.first+1][cur.second] == false){
        max = matrix[cur.first+1][cur.second];
        next = make_pair(cur.first+1, cur.second);
    }
    //left
    if(matrix[cur.first][cur.second-1] > max
    &&visited[cur.first][cur.second-1] == false){
        max = matrix[cur.first][cur.second-1];
        next = make_pair(cur.first, cur.second-1);
    }
    //right
    if(matrix[cur.first][cur.second+1] > max
    &&visited[cur.first][cur.second+1] == false){
        max = matrix[cur.first][cur.second+1];
        next = make_pair(cur.first, cur.second+1);
    }
    find(next, index+1, sum, visited);
}

int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> matrix[i][j];
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            bool vi[502][502] = {false, };
            int tmp = find(make_pair(i,j),1,0, vi);
            if(tmp > ret){
                ret = tmp;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
