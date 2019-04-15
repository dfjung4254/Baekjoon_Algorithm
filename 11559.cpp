#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/* up, right, down, left */
const int dir_i[4] = {-1, 0, 1, 0};
const int dir_j[4] = {0, 1, 0, -1};
char matrix[12][6];
bool visited[12][6];
queue<pair<int, int>> q;
vector<pair<int, int>> st;
int chainCount = 0;

void gravity(){

    for (int j = 0; j < 6; j++){
        for (int i = 11; i >= 0; i--){
            if(matrix[i][j] == '.'){
                int ni = i;
                while(ni > 0){
                    ni--;
                    if(matrix[ni][j] != '.'){
                        matrix[i][j] = matrix[ni][j];
                        matrix[ni][j] = '.';
                        break;
                    }
                }
            }
        }
    }
}

bool check(){

    bool ret = false;
    /* visited init */
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 6; j++){
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 6; j++){
            if(matrix[i][j] != '.' && !visited[i][j]){
                st.clear();
                char ch = matrix[i][j];
                visited[i][j] = true;
                q.push(make_pair(i, j));
                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    st.push_back(cur);
                    q.pop();
                    for (int dir = 0; dir < 4; dir++){
                        int n_i = cur.first + dir_i[dir];
                        int n_j = cur.second + dir_j[dir];
                        if(n_i >= 0 && n_i < 12 && n_j >= 0 && n_j < 6 && !visited[n_i][n_j]
                        && matrix[n_i][n_j] == ch){
                            visited[n_i][n_j] = true;
                            q.push(make_pair(n_i, n_j));
                        }
                    }
                }
                if(st.size() >= 4){
                    ret = true;
                    for(pair<int, int> pa : st){
                        matrix[pa.first][pa.second] = '.';
                    }
                }
            }
        }
    }

    return ret;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 6; j++){
            cin >> matrix[i][j];
        }
    }

    while(check()){
        chainCount++;
        gravity();
    }

    cout << chainCount << '\n';

    return 0;
}