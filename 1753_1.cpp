#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 1000000000
using namespace std;

int v, e, init;
struct Vertex{
    int idx, dist = INF;
    vector<pair<int, int>> next;
    bool operator < (const Vertex &v) const{
        return dist > v.dist;
    }
};
Vertex vertex[MAX];

void dijkstra(){
    priority_queue<Vertex> pq;
    pq.push(vertex[init]);
    while(!pq.empty()){
        Vertex curVertex = pq.top();
        pq.pop();
        for(pair<int, int> pa : curVertex.next){
            if(vertex[pa.second].dist > curVertex.dist + pa.first){
                vertex[pa.second].dist = curVertex.dist + pa.first;
                pq.push(vertex[pa.second]);
            }
        }
    }
}

void rPrint(){
    for(int i = 1; i <= v; i++){
        if(vertex[i].dist >= INF){
            cout << "INF" << '\n';
            continue;
        }
        cout << vertex[i].dist << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> e >> init;
    for(int i = 1; i <= v; i++){
        vertex[i].idx = i;
    }
    vertex[init].dist = 0;
    while(e--){
        int u, v, w;
        cin >> u >> v >> w;
        vertex[u].next.push_back(make_pair(w, v));
    }
    dijkstra();
    rPrint();
    return 0;
}
