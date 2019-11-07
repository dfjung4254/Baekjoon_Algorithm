#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

bool matrix[1001][1001];
bool visited[1001];

void dfs(int v, int size){
    visited[v] = true;
    cout << v << " ";
    for(int i = 1; i <= size; i++){
        if(matrix[v][i] && visited[i] == false){
            dfs(i, size);
        }
    }
}

void bfs(int v, int size){
    queue<int> queue;
    visited[v] = true;
    queue.push(v);
    cout << v << " ";
    while(!queue.empty()){
        int a = queue.front();
        queue.pop();
        for(int i = 1; i <= size; i++){
            if(matrix[a][i] && visited[i] == false){
                queue.push(i);
                cout << i << " ";
                visited[i] = true;
            }
        }
    }
}

int main(){

    int n, m, v;
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        matrix[a][b] = true;
        matrix[b][a] = true;
    }
    dfs(v, n);
    memset(visited, false, sizeof(bool)*1001);
    cout << '\n';
    bfs(v, n);

    return 0;
}
