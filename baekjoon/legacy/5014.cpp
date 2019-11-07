#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int f, cur, target, up, down;
int visited[1000001] = {-1, };
int _min = 987654321;
queue<int> q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> f >> cur >> target >> up >> down;
    memset(visited, -1, sizeof(visited));
    q.push(cur);
    visited[cur] = 0;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        //up
        int n_up = current + up;
        if(n_up <= 1000000 && visited[n_up] == -1){
            visited[n_up] = visited[current] + 1;
            q.push(n_up);
        }
        //down
        int n_down = current - down;
        if(n_down > 0 && visited[n_down] == -1){
            visited[n_down] = visited[current] + 1;
            q.push(n_down);
        }
    }
    if(visited[target] == -1){
        cout << "use the stairs" << '\n';
    }else{
        cout << visited[target] << '\n';
    }

    return 0;
}