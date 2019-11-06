#include <iostream>
#define MAX 101
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
        int a, b, w;
        cin >> a >> b >> w;
        if(matrix[a][b] > w){
            matrix[a][b] = w;
        }
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
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(matrix[i][j] == INF)
                matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}