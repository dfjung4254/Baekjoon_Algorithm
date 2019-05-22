#include <iostream>
#include <queue>
using namespace std;

char matrix[31][31][31];
int visited[31][31][31];
// up , right, down, left, top, bottom
int dir_k[6] = {0, 0, 0, 0, 1, -1};
int dir_i[6] = {-1, 0, 1, 0, 0, 0};
int dir_j[6] = {0, 1, 0, -1, 0, 0};

struct Point{
    int k, i, j;
};
Point _inits;
Point _exits;
queue<Point> q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        int l, r, c;
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0){
            break;
        }
        for (int k = 1; k <= l; k++){
            for (int i = 1; i <= r; i++){
                for (int j = 1; j <= c; j++){
                    cin >> matrix[k][i][j];
                    visited[k][i][j] = -1;
                    if(matrix[k][i][j] == 'S'){
                        _inits.k = k;
                        _inits.i = i;
                        _inits.j = j;
                    }
                    if(matrix[k][i][j] == 'E'){
                        _exits.k = k;
                        _exits.i = i;
                        _exits.j = j;
                    }
                }
            }
        }
        q.push(_inits);
        visited[_inits.k][_inits.i][_inits.j] = 0;
        while(!q.empty()){
            Point cp = q.front();
            q.pop();
            for (int dir = 0; dir < 6; dir++){
                Point np;
                np.k = cp.k + dir_k[dir];
                np.i = cp.i + dir_i[dir];
                np.j = cp.j + dir_j[dir];
                if(np.k > 0 && np.k <= l && np.i > 0 && np.i <= r
                && np.j > 0 && np.j <= c && visited[np.k][np.i][np.j] == -1
                && matrix[np.k][np.i][np.j] != '#'){
                    visited[np.k][np.i][np.j] = visited[cp.k][cp.i][cp.j] + 1;
                    q.push(np);
                }
            }
        }
        if(visited[_exits.k][_exits.i][_exits.j] == -1){
            cout << "Trapped!" << '\n';
        }else{
            cout << "Escaped in " << visited[_exits.k][_exits.i][_exits.j] << " minute(s)." << '\n';
        }
    }

    return 0;
}