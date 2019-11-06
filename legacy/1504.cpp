#include <iostream>
#include <vector>
#include <queue>
#define MAX 801
#define INF 2000000000
using namespace std;

int n, m, n1, n2;
class Node{
public:
    int idx, dist;
    vector<pair<int, int>> next;
    Node(int idx = 0, int dist = INF)
    :idx(idx), dist(dist) {}
    bool operator < (const Node &nd) const {
        return dist > nd.dist;
    }
};
Node node[MAX];
void initNode(){
    for(int i = 1; i <= n; i++){
        node[i].dist = INF;
    }
}

void dijkstra(int init, int tar1, int tar2, int &rt1, int &rt2){
    initNode();
    priority_queue<Node> pq;
    node[init].dist = 0;
    pq.push(node[init]);
    while(!pq.empty()){
        Node curNode = pq.top();
        pq.pop();
        for(pair<int, int> pa : curNode.next){
            if(node[pa.second].dist > curNode.dist + pa.first){
                node[pa.second].dist = curNode.dist + pa.first;
                pq.push(node[pa.second]);
            }
        }
    }
    rt1 = node[tar1].dist;
    rt2 = node[tar2].dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        node[i].idx = i;
    }
    while(m--){
        int i, j, w;
        cin >> i >> j >> w;
        node[i].next.push_back(make_pair(w, j));
        node[j].next.push_back(make_pair(w, i));
    }
    cin >> n1 >> n2;
    int rt1, rt2, rt3, rt4, rt5, fnr1, fnr2;
    dijkstra(1, n1, n2, rt1, rt2);
    dijkstra(n1, n2, n2, rt3, rt3);
    dijkstra(n, n1, n2, rt4, rt5);
    fnr1 = rt1 + rt3 + rt5;
    fnr2 = rt2 + rt3 + rt4;
    if(rt1 == INF || rt3 == INF || rt5 == INF){
        fnr1 = -1;
    }
    if(rt2 == INF || rt3 == INF || rt4 == INF){
        fnr2 = -1;
    }
    int ret = (fnr1 > fnr2) ? fnr2 : fnr1;
    cout << ret << endl;
    return 0;
}
