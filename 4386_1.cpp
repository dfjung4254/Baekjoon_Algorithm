#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int n;
class Planet{
public:
    double x, y;    
    Planet(double x = 0, double y = 0)
    :x(x), y(y) {}
};
class Tunnel{
public:
    int i;
    int j;
    double w;
    Tunnel(int i = 0, int j = 0, double w = 0)
    :i(i), j(j), w(w) {}
    bool operator <(const Tunnel &t) const{
        return w < t.w;
    }
};
vector<Tunnel> tunnel;
Planet planet[101];
int vRoot[101] = {0, };
double ret = 0;

double getDist(Planet p1, Planet p2){
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

int findRoot(int v){
    if(vRoot[v] == v) return v;
    return vRoot[v] = findRoot(vRoot[v]);
}

void kruskal(){
    sort(tunnel.begin(), tunnel.end());
    for(Tunnel t : tunnel){
        int ri = findRoot(t.i);
        int rj = findRoot(t.j);
        if(ri != rj){
            // no -cycle merge.
            vRoot[rj] = ri;
            ret += t.w;
        }
    }
    cout << setprecision(3) << ret << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> planet[i].x >> planet[i].y;
        vRoot[i] = i;
    }
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            //set Tunnels
            tunnel.push_back(Tunnel(i, j, getDist(planet[i], planet[j])));
        }
    }
    kruskal();

    return 0;
}
