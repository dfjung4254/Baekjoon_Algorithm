#include <iostream>
#define MAX 101
#define INF 987654321
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
        matrix[b][a] = 1;
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
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(matrix[1][i] != INF && matrix[1][i] != 0)
            count++;
    }
    cout << count << '\n';

    return 0;
}