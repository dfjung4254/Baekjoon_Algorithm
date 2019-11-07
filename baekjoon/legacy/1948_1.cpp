#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

struct City{
    int dist = 0, idx, indegree = 0;
    vector<pair<int, int>> next;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    City city[n+1];
    City reCity[n+1];
    bool visited[n+1];
    for(int i = 1; i <= n; i++){
        reCity[i].idx = i;
        city[i].idx = i;
    }
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        city[a].next.push_back(make_pair(w, b));
        reCity[b].next.push_back(make_pair(w, a));
        city[b].indegree++;
    }
    int init, target;
    cin >> init >> target;
    queue<int> pq;
    pq.push(init);
    while(!pq.empty()){
        int cIdx = pq.front();
        pq.pop();
        for(pair<int, int> pa : city[cIdx].next){
            int w = pa.first;
            int nIdx = pa.second;
            if(city[nIdx].dist < city[cIdx].dist + w){
                city[nIdx].dist = city[cIdx].dist + w;
            }
            if(--city[nIdx].indegree == 0){
                pq.push(nIdx);
            }
        }
    }
    cout << city[target].dist << '\n';
    int count = 0;
    pq.push(target);
    while(!pq.empty()){
        int cIdx = pq.front();
        pq.pop();
        for(pair<int, int> pa : reCity[cIdx].next){
            int w = pa.first;
            int nIdx = pa.second;
            if(city[nIdx].dist + w == city[cIdx].dist){
                count++;
                if(!visited[nIdx]){
                    visited[nIdx] = true;
                    pq.push(nIdx);
                }
            }
        }
    }
    cout << count << '\n';

    return 0;
}