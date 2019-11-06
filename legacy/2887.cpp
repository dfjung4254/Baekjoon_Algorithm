#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, minCost = 0;
class Planet{
public:
    int x, y, z, idx;
    Planet(int x = 0, int y = 0, int z = 0, int i = 0)
    :x(x), y(y), z(z), idx(i) {}
};
Planet planet[100001];
bool cmpx(Planet a, Planet b){
    return a.x < b.x;
}
bool cmpy(Planet a, Planet b){
    return a.y < b.y;
}
bool cmpz(Planet a, Planet b){
    return a.z < b.z;
}
class Tunnel{
public:
    int i;
    int j;
    int cost;
    Tunnel(int i, int j, int cost)
    :i(i), j(j), cost(cost) {}
    bool operator <(const Tunnel &t) const{
        return cost < t.cost;
    }
};
vector<Tunnel> tunnel;
int vRoot[100001] = {0, };

int findRoot(int v){
    if(vRoot[v] == v) return v;
    return vRoot[v] = findRoot(vRoot[v]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> planet[i].x >> planet[i].y >> planet[i].z;
        planet[i].idx = i;
    }
    sort(planet+1, planet+n+1, cmpx);
    for(int i = 1; i <= n-1; i++){
        tunnel.push_back(Tunnel(planet[i].idx, planet[i+1].idx, abs(planet[i].x-planet[i+1].x)));
    }
    sort(planet+1, planet+n+1, cmpy);
    for(int i = 1; i <= n-1; i++){
        tunnel.push_back(Tunnel(planet[i].idx, planet[i+1].idx, abs(planet[i].y-planet[i+1].y)));
    }
    sort(planet+1, planet+n+1, cmpz);
    for(int i = 1; i <= n-1; i++){
        tunnel.push_back(Tunnel(planet[i].idx, planet[i+1].idx, abs(planet[i].z-planet[i+1].z)));
    }
    sort(tunnel.begin(), tunnel.end());
    for(int i = 1; i <= n; i++){
        vRoot[i] = i;
    }
    for(Tunnel t : tunnel){
        int rootI = findRoot(t.i);
        int rootJ = findRoot(t.j);
        if(rootI != rootJ){
            //cout << t.i << " - " << t.j << " connected(" << t.cost << ")" << '\n';
            minCost += t.cost;
            vRoot[rootJ] = rootI;
        }
    }
    cout << minCost << endl;

    return 0;
}
