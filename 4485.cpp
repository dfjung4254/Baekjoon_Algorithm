#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        int tc = 0;
    while(++tc){
        int n;
        cin >> n;
        if(n==0)
            break;
        int matrix[n][n];
        bool visited[n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> matrix[i][j];
                
            }
        }
    }
    return 0;
}