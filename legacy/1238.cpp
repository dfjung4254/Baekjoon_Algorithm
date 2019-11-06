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
int dist[MAX] = {0, };

void dijkstra(int i){
    for(int idx = 1; idx <= n; idx++){
        vertex[idx].dist = INF;
    }
    vertex[i].dist = 0;
    priority_queue<Vertex> pq;
    pq.push(vertex[i]);
    while(!pq.empty()){
        Vertex curVertex = pq.top();
        pq.pop();
        for(pair<int, int> pa : curVertex.next){
            int tWeight = pa.first;
            int tVertex = pa.second;
            if(vertex[tVertex].dist > curVertex.dist + tWeight){
                vertex[tVertex].dist = curVertex.dist + tWeight;
                pq.push(vertex[tVertex]);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> init;
    while(m--){
        int i, j, w;
        cin >> i >> j >> w;
        vertex[i].next.push_back(make_pair(w, j));
    }
    dijkstra(init);
    for(int i = 1; i <= n; i++){
        dist[i] += vertex[i].dist;
    }
    for(int i = 1; i <= n; i++){
        dijkstra(i);
        dist[i] += vertex[init].dist;
    }
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(ret < dist[i]){
            ret = dist[i];
        }
    }
    cout << ret << '\n';

    return 0;
}