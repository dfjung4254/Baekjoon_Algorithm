#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
#define MAX 20001
using namespace std;

int v, e, init;
class Vertex{
public:
    int idx;
    int dist;
    int post;
    vector<pair<int, int>> edges;
    Vertex(int i = 0, int d = INF, int p = 0)
    :idx(i), dist(d), post(p) {}
    bool operator < (const Vertex &v) const{
        return dist > v.dist;
    }
};
Vertex vtx[MAX];

void dijkstra(){
    priority_queue<Vertex> pq;
    pq.push(vtx[init]);
    while(!pq.empty()){
        Vertex curV = pq.top();
        pq.pop();
        for(pair<int, int> edge : curV.edges){
            int toIdx = edge.second;
            int weight = edge.first;
            if(vtx[toIdx].dist > curV.dist + weight){
                vtx[toIdx].dist = curV.dist + weight;
                pq.push(vtx[toIdx]);
            }
        }
    }
    for(int i = 1; i <= v; i++){
        int dt = vtx[i].dist;
        if(dt == INF){
            cout << "INF" << '\n';
        }else{
            cout << dt << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> e;
    for(int i = 1; i <= v; i++){
        vtx[i].idx = i;
    }
    cin >> init;
    vtx[init].dist = 0;
    while(e--){
        int i, j, w;
        cin >> i >> j >> w;
        vtx[i].edges.push_back(make_pair(w, j));
    }
    dijkstra();
    return 0;
}
