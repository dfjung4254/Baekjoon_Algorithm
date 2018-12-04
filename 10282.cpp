#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define INF 2000000000
using namespace std;

struct Com{
    int dist = INF;
    vector<pair<int, int>> next;
    bool operator < (const Com &c) const {
        return dist > c.dist;
    }
};
Com com[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n, d, c, count = 1, max = 0;
        cin >> n >> d >> c;
        for(int i = 1; i <= n; i++){
            com[i].dist = INF;
            com[i].next.clear();
        }
        while(d--){
            int j, i, w;
            cin >> j >> i >> w;
            com[i].next.push_back(make_pair(w, j));
        }
        priority_queue<Com> pq;
        com[c].dist = 0;
        pq.push(com[c]);
        while(!pq.empty()){
            Com curCom = pq.top();
            pq.pop();
            for(pair<int, int> pa : curCom.next){
                int w = pa.first;
                int idx = pa.second;
                if(com[idx].dist > curCom.dist + w){
                    if(com[idx].dist == INF) count++;
                    com[idx].dist = curCom.dist + w;
                    pq.push(com[idx]);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            int td = com[i].dist;
            if(td != INF && td > max)
                max = td;
        }
        cout << count << " " << max << '\n';
    }

    return 0;
}