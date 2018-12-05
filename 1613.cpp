#include <iostream>
#define MAX 401
#define INF 1000000000
using namespace std;

int matrix[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            matrix[i][j] = (i==j) ? 0:INF;
        }
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(matrix[a][b] != INF && matrix[b][a] == INF){
            cout << -1 << '\n';
        }else if(matrix[b][a] != INF && matrix[a][b] == INF){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }

    return 0;
}