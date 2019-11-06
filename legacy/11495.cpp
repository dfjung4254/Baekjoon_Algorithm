#include <iostream>
using namespace std;

int matrix[51][51];
int n, m;
int ret;

void goWidthMatrix(int i, int j){
    while(true){
        if(matrix[i][j] != 0 && matrix[i][j+1] != 0){
            matrix[i][j]--;
            matrix[i][j+1]--;
            ret++;
        }else{
            break;
        }
    }
}

void goHeightMatrix(int i, int j){
    while(true){
        if(matrix[i][j] != 0 && matrix[i+1][j] != 0){
            matrix[i][j]--;
            matrix[i+1][j]--;
            ret++;
        }else{
            break;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        ret = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){        
                cin >> matrix[i][j];
            }
        }

        //격자순회
        //가로탐방
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m-1; j++){
                goWidthMatrix(i, j);
            }
        }
        //세로탐방
        for(int i = 1; i <= n-1; i++){
            for(int j = 1; j <= m; j++){
                goHeightMatrix(i, j);
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(matrix[i][j] != 0){
                    ret += matrix[i][j];
                }
            }
        }

        cout << ret << '\n';

    }

    return 0;   
}