#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1000000000
using namespace std;

int n, m;
class Com{
public:
    int idx, dist, post;
    vector<pair<int, int>> next;
    Com(int i = 0, int d = INF, int p = -1)
    :idx(i), dist(d), post(p) {}
    bool operator < (const Com &c) const {
        return dist > c.dist;
    }
};
Com com[MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> ret;

void dijkstra(){
    priority_queue<Com> pq;
    com[1].dist = 0;
    pq.push(com[1]);
    while(!pq.empty()){
        Com curCom = pq.top();
        pq.pop();
        for(pair<int, int> p : curCom.next){
            if(com[p.second].dist > curCom.dist + p.first){
                com[p.second].dist = curCom.dist + p.first;
                com[p.second].post = curCom.idx;
                pq.push(com[p.second]);
            }
        }
    }
    for(int i = 2; i <= n; i++){
        Com tpc = com[i];
        while(tpc.dist != 0){
            if(!visited[tpc.idx][tpc.post]){
                ret.push_back(make_pair(tpc.idx, tpc.post));
                visited[tpc.idx][tpc.post] = true;
                visited[tpc.post][tpc.idx] = true;
            }
            tpc = com[tpc.post];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        com[i].idx = i;
    }
    while(m--){
        int i, j, w;
        cin >> i >> j >> w;
        com[i].next.push_back(make_pair(w, j));
        com[j].next.push_back(make_pair(w, i));
    }
    dijkstra();
    cout << ret.size() << '\n';
    for(pair<int, int> p : ret){
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}
