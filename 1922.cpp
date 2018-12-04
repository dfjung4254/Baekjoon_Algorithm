#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define line pair<int, int>
#define weight first
#define idx second
using namespace std;

int n, m;
vector<line> com[MAX];
bool visited[MAX] = {false, };
priority_queue<line, vector<line>, greater<line>> pq;
int cost = 0;

void prim(int init){
    visited[init] = true;
    for(line pa : com[init]){
        pq.push(pa);
    }
    while(!pq.empty()){
        line curEdge = pq.top();
        pq.pop();
        if(visited[curEdge.idx]) continue;
        visited[curEdge.idx] = true;
        cost += curEdge.weight;
        for(line pa : com[curEdge.idx]){
            if(!visited[pa.idx]){
                pq.push(pa);                
            }

        }
    }
    cout << cost << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int u, v, weight;
        cin >> u >> v >> weight;
        com[u].push_back(make_pair(weight, v));
        com[v].push_back(make_pair(weight, u));
    }
    prim(1);
    return 0;
}
