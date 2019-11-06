#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
vector<pair<int, int>> node[100001];
bool visited[100001] = {false, };
int init, target;
int low, high;
queue<int> q;

bool bfs(int dist){

    memset(visited, false, sizeof(visited));
    q.push(init);
    visited[init] = true;
    while(!q.empty()){
        int cur_idx = q.front();
        q.pop();
        for(pair<int, int> pa : node[cur_idx]){
            if(pa.first >= dist && !visited[pa.second]){
                q.push(pa.second);
                visited[pa.second] = true;
            }
        }
    }
    return visited[target];
}

int bSearch(){

    while(low <= high){
        int mid = (low + high) / 2;
        if(bfs(mid)){
            low = mid + 1;
        }else{
            high = mid - 1;            
        }
    }
    return high;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /* empty */
    cin >> n >> m;
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        node[a].push_back(make_pair(w, b));
        node[b].push_back(make_pair(w, a));
    }
    cin >> init >> target;
    low = 1;
    high = 1000000000;

    cout << bSearch() << '\n';

    return 0;
}