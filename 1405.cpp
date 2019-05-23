#include <iostream>
#include <iomanip>
using namespace std;

const int dir_i[4] = {0, 0, 1, -1};
const int dir_j[4] = {1, -1, 0, 0};
double dir_rate[4];
int n;
bool visited[31][31];
double ans = 0;

void dfs(int index, int i, int j, double rate){

    if(index == n){
        ans += rate;
        return;
    }

    for (int dir = 0; dir < 4; dir++){
        int ni = i + dir_i[dir];
        int nj = j + dir_j[dir];
        if(!visited[ni][nj]){
            visited[ni][nj] = true;
            dfs(index + 1, ni, nj, rate * dir_rate[dir]);
            visited[ni][nj] = false;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> dir_rate[0] >> dir_rate[1] >> dir_rate[2] >> dir_rate[3];
    dir_rate[0] *= 0.01;
    dir_rate[1] *= 0.01;
    dir_rate[2] *= 0.01;
    dir_rate[3] *= 0.01;

    /*
    
        일단 모든 가능성 탐색.
    
    */
    visited[15][15] = true;
    dfs(0, 15, 15, 1.0);

    cout << fixed;
    cout << setprecision(10) << ans << '\n';

    return 0;
}