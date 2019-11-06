#include <iostream>
#define MAX 103
#define INF 1000000000
using namespace std;

int matrix[MAX][MAX];
pair<int, int> pMatrix[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        for(int i = 1; i <= n+2; i++){
            for(int j = 1; j <= n+2; j++){
                matrix[i][j] = (i==j) ? 0:INF;
            }
        }
        cin >> pMatrix[1].first >> pMatrix[1].second;
        for(int i = 3; i <= n+2; i++){
            cin >> pMatrix[i].first >> pMatrix[i].second;
        }
        cin >> pMatrix[2].first >> pMatrix[2].second;
        for(int i = 1; i <= n+1; i++){
            for(int j = i+1; j <= n+2; j++){
                int dist = abs(pMatrix[i].first-pMatrix[j].first)
                            + abs(pMatrix[i].second-pMatrix[j].second);
                if(dist <= 1000){
                    matrix[i][j] = 1;
                    matrix[j][i] = 1;
                }
            }
        }
        for(int i = 1; i <= n+2; i++){
            for(int j = 1; j <= n+2; j++){
                for(int k = 1; k <= n+2; k++){
                    if(matrix[j][k] > matrix[j][i] + matrix[i][k]){
                        matrix[j][k] = matrix[j][i] + matrix[i][k];
                    }
                }
            }
        }
        if(matrix[1][2] != INF){
            cout << "happy" << '\n';
        }else{
            cout << "sad" << '\n';
        }
    }


    return 0;
}