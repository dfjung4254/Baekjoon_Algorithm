#include <iostream>

using namespace std;

int n;
int matrix[17][17];
int ans = 0;
enum{
    HORIZONTAL,
    VERTICAL,
    DIAGONAL
};

void dfs(int shape, pair<int, int> target){

    if(target.first == n && target.second == n){
        ans++;
        return;
    }

    /* 1. 가로인 경우 2. 세로인 경우 3. 대각선인 경우 */
    switch(shape){
        case HORIZONTAL:
            /* 가로, 대각선 체크 */
            
        break;
        case VERTICAL:
            /* 세로, 대각선 체크 */

        break;
        case DIAGONAL:
            /* 가로, 대각선, 세로 체크 */

        break;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }

    dfs(HORIZONTAL, make_pair(1,2));

    cout << ans << '\n';

    return 0;
}