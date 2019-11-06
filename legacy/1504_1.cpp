#include <iostream>
#include <queue>
#include <vector>
#define MAX 801
#define INF 1000000000
using namespace std;

int n, e, n1, n2, r1, r2, r3, r4, r5;
int route1, route2;

struct Vertex{
    int idx, dist = INF;
    vector<pair<int, int>> next;
    bool operator < (const Vertex &v) const {
        return dist > v.dist;
    }
};
Vertex vertex[MAX];

void reset(){
    for(int i = 1; i <= n; i++){
        vertex[i].dist = INF;
    }
}

void dijkstra(int init, int target1, int target2, int &dist1, int &dist2){
    reset();
    priority_queue<Vertex> pq;
    vertex[init].dist = 0;
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
    dist1 = vertex[target1].dist;
    dist2 = vertex[target2].dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    for(int i = 1; i <= n; i++){
        vertex[i].idx = i;
    }
    while(e--){
        int i, j, w;
        cin >> i >> j >> w;
        vertex[i].next.push_back(make_pair(w, j));
        vertex[j].next.push_back(make_pair(w, i));
    }
    cin >> n1 >> n2;
    dijkstra(1, n1, n2, r1, r2);
    dijkstra(n1, n2, n2, r3, r3);
    dijkstra(n, n1, n2, r4, r5);
    route1 = r1+r3+r5;
    route2 = r2+r3+r4;
    int ret;
    if(r1 == INF || r3 == INF || r5 == INF
    || r4 == INF || r2 == INF){
        ret = -1;
    }else{
        ret = (route1 > route2) ? route2:route1;
    }

    cout << ret << '\n';

    return 0;
}
