#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 1000000000
using namespace std;

int n, m, init;
struct Vertex{
    int dist = INF;
    vector<pair<int, int>> next;
    bool operator < (const Vertex &v) const {
        return dist > v.dist;
    }
};
Vertex vertex[MAX];
Vertex reVertex[MAX];
int dist[MAX];

void dijkstra(Vertex v[]){
    v[init].dist = 0;
    priority_queue<Vertex> pq;
    pq.push(v[init]);
    while(!pq.empty()){
        Vertex curV = pq.top();
        pq.pop();
        for(pair<int, int> pa : curV.next){
            int w = pa.first;
            int idx = pa.second;
            if(v[idx].dist > curV.dist + w){
                v[idx].dist = curV.dist + w;
                pq.push(v[idx]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        dist[i] += v[i].dist;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> init;
    int c = m;
    while(c--){
        int i, j, w;
        cin >> i >> j >> w;
        vertex[i].next.push_back(make_pair(w, j));
        reVertex[j].next.push_back(make_pair(w, i));
    }
    dijkstra(vertex);
    dijkstra(reVertex);
    sort(dist+1, dist+1+n);
    cout << dist[n] << '\n';

    return 0;
}