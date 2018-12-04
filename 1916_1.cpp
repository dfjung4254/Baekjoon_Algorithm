#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1000000000
using namespace std;

int n, m, init, target;
struct City{
    int idx, dist = INF;
    vector<pair<int, int>> next;
    bool operator < (const City &c) const {
        return dist > c.dist;
    }
};
City city[MAX];

void dijkstra(){
    priority_queue<City> pq;
    pq.push(city[init]);
    while(!pq.empty()){
        City curCity = pq.top();
        pq.pop();
        for(pair<int, int> pa : curCity.next){
            if(city[pa.second].dist > curCity.dist + pa.first){
                city[pa.second].dist = curCity.dist + pa.first;
                pq.push(city[pa.second]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        city[i].idx = i;
    }
    while(m--){
        int i, j, w;
        cin >> i >> j >> w;
        city[i].next.push_back(make_pair(w, j));

    }
    cin >> init >> target;
    city[init].dist = 0;
    dijkstra();
    cout << city[target].dist << '\n';
    return 0;
}
