#include <iostream>
#include <string.h>
using namespace std;

int matrix[15][15];

void setMatrix(){
    memset(matrix, 0, sizeof(matrix));
    for(int i = 1; i < 15; i++){
        matrix[0][i] = i;
        matrix[i][1] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n, k;
        cin >> n >> k;
        setMatrix();
        for(int i = 1; i < 15; i++){
            for(int j = 2; j < 15; j++){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        cout << matrix[n][k] << '\n';
    }


    return 0;
}