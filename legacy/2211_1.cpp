#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 2000000000
using namespace std;

int n, m;
struct Com{
    int idx, dist = INF, post = 0;
    vector<pair<int, int>> next;
    bool operator < (const Com &c) const {
        return dist > c.dist;
    }
};
Com com[MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> recovered;

void traceNetwork(){
    for(int i = 1; i <= n; i++){
        Com cur = com[i];
        while(cur.post != 0){
            if(!visited[cur.idx][cur.post]){
                visited[cur.idx][cur.post] = true;
                visited[cur.post][cur.idx] = true;
                recovered.push_back(make_pair(cur.idx, cur.post));
            }
            cur = com[cur.post];
        }
    }
}

void netPrint(){
    cout << recovered.size() << '\n';
    for(pair<int, int> pa : recovered){
        cout << pa.first << " " << pa.second << '\n';
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
    //dijkstra algorithm
    priority_queue<Com> pq;
    com[1].dist = 0;
    pq.push(com[1]);
    while(!pq.empty()){
        Com curCom = pq.top();
        pq.pop();
        for(pair<int, int> pa : curCom.next){
            if(com[pa.second].dist > curCom.dist + pa.first){
                com[pa.second].dist = curCom.dist + pa.first;
                com[pa.second].post = curCom.idx;
                pq.push(com[pa.second]);
            }
        }
    }
    traceNetwork();
    netPrint();

    return 0;
}
