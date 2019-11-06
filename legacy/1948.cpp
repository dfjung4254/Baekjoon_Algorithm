#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

struct City{
    int dist = 0;
    int indegree = 0;
    int idx = 0;
    vector<pair<int, int>> next;
};
City city[MAX];
City reCity[MAX];
bool checked[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        city[i].idx = i;
        reCity[i].idx = i;
    }
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        city[a].next.push_back(make_pair(w, b));
        city[b].indegree++;
        reCity[b].next.push_back(make_pair(w, a));
    }
    int init, target;
    cin >> init >> target;
    queue<City> pq;
    pq.push(city[init]);
    while(!pq.empty()){
        City curCity = pq.front();
        pq.pop();
        for(pair<int, int> pa : curCity.next){
            int nIdx = pa.second;
            int w = pa.first;
            if(city[nIdx].dist < curCity.dist + w){
                city[nIdx].dist = curCity.dist + w;
            }
            if(--city[nIdx].indegree == 0){
                pq.push(city[nIdx]);
            }
        }
    }
    cout << city[target].dist << '\n';
    int count = 0;
    queue<City> q;
    q.push(reCity[target]);
    while(!q.empty()){
        City curCity = q.front();
        q.pop();
        int cIdx = curCity.idx;
        for(pair<int, int> pa : curCity.next){
            int w = pa.first;
            int nIdx = pa.second;
            if(city[nIdx].dist + w == city[cIdx].dist && !checked[cIdx][nIdx]){
                checked[cIdx][nIdx] = true;
                count++;
                q.push(reCity[nIdx]);
            }
        }
    }
    cout << count << '\n';

    return 0;
}