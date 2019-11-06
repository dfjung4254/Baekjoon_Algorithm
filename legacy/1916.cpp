#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1000000000
#define bus pair<int, int>
#define weight first
#define dir second
using namespace std;

int n, m, init, target;
class City{
public:
    int dist, idx;
    vector<bus> next;
    City(int i = 0, int d = INF, int p = 0)
    :idx(i), dist(d) {}
    bool operator < (const City &c) const {
        return dist > c.dist;
    }
};
City city[MAX];

void dijkstra(){
    priority_queue<City> pq;
    city[init].dist = 0;
    pq.push(city[init]);
    while(!pq.empty()){
        City curCity = pq.top();
        pq.pop();
        for(bus b : curCity.next){
            if(city[b.dir].dist > curCity.dist + b.weight){
                city[b.dir].dist = curCity.dist + b.weight;
                pq.push(city[b.dir]);
            }
        }
    }
    cout << city[target].dist << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        city[i].idx = i;
    }
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        city[a].next.push_back(make_pair(c, b));
    }
    cin >> init >> target;
    dijkstra();
    return 0;
}
