#include <iostream>
#include <queue>
using namespace std;

int matrix[300][300];
queue<pair<int, int>> q;
const int dir_i[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dir_j[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        for (int i = 0; i < 300; i++){
            for (int j = 0; j < 300; j++){
                matrix[i][j] = -1;
            }
        }
        int n, ci, cj, ti, tj;
        cin >> n;
        cin >> ci >> cj;
        cin >> ti >> tj;

        q.push(make_pair(ci, cj));
        matrix[ci][cj] = 0;
        while(!q.empty()){
            int c_i = q.front().first;
            int c_j = q.front().second;
            q.pop();
            for (int dir = 0; dir < 8; dir++){
                int ni = c_i + dir_i[dir];
                int nj = c_j + dir_j[dir];
                if(ni >= 0 && ni < n && nj >= 0 && nj < n && matrix[ni][nj] == -1){
                    matrix[ni][nj] = matrix[c_i][c_j] + 1;
                    q.push(make_pair(ni, nj));
                }
            }
        }
        cout << matrix[ti][tj] << '\n';
    }

    return 0;
}