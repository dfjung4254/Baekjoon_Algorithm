#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n;
int matrix[101][101];
int visited[101] = {false, };
int ans[101][101];
queue<int> q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        q.push(i);
        while(!q.empty()){
            int cIdx = q.front();
            q.pop();
            for (int j = 1; j <= n; j++)
            {
                if(matrix[cIdx][j] == 1 && !visited[j]){
                    ans[i][j] = 1;
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}