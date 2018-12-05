#include <iostream>
#define MAX 101
#define INF 1000000000
using namespace std;

int n, m;
int matrix[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(matrix[j][k] > matrix[j][i] + matrix[i][k]){
                    matrix[j][k] = matrix[j][i] + matrix[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 1; j <= n; j++){
            if(i==j) continue;
            if(!(matrix[i][j] != INF || matrix[j][i] != INF)){
                count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}