#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

struct Node{
    vector<int> nextIdx;
    bool isCycle = false;
    int dist = 0;
};
Node nodes[3001];
bool visited[3001];
int n;
int bfsInit;
queue<int> q;

void checkCycle(int idx, int init, bool isFirst, int before){

    if(idx == init && !isFirst){
        nodes[idx].isCycle = true;
        bfsInit = idx;
        return;
    }

    for(int nIdx : nodes[idx].nextIdx){
        if(!visited[nIdx] || (nIdx == init && before != init)){
            visited[nIdx] = true;
            checkCycle(nIdx, init, false, idx);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        nodes[a].nextIdx.push_back(b);
        nodes[b].nextIdx.push_back(a);
    }

    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(bool) * 3001);
        visited[i] = true;
        checkCycle(i, i, true, i);
    }

    memset(visited, false, sizeof(bool) * 3001);

    visited[bfsInit] = true;
    q.push(bfsInit);
    while(!q.empty()){
        int curIdx = q.front();
        int curDist = nodes[curIdx].dist;
        q.pop();
        for(int nIdx : nodes[curIdx].nextIdx){
            if(!visited[nIdx]){
                if(!nodes[nIdx].isCycle){
                    nodes[nIdx].dist = curDist + 1;
                }
                visited[nIdx] = true;
                q.push(nIdx);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << nodes[i].dist << " ";
    }
    cout << '\n';

    return 0;
}