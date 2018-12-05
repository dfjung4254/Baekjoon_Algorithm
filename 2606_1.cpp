#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int matrix[MAX][MAX];
bool visited[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    int count = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(matrix[cur][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
                count++;
            }
        }
    }
    cout << count << '\n';

    return 0;
}