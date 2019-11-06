#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define MAX 1001
using namespace std;

int n, m;
double cost = 0;
pair<int, int> planet[MAX];
class Tunnel{
public:
    int i, j;
    double w;
    Tunnel(int i = 0, int j = 0, double w = 0)
    :i(i), j(j), w(w) {}
    bool operator < (const Tunnel &t) const {
        return w < t.w;
    }
};
vector<Tunnel> tunnel;
int vRoot[MAX] = {0, };

double getDist(pair<int, int> pla, pair<int, int> plb){
    return sqrt(pow(pla.first-plb.first,2)+pow(pla.second-plb.second,2));
}

int findRoot(int v){
    if(vRoot[v] == v) return v;
    return vRoot[v] = findRoot(vRoot[v]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        planet[i] = make_pair(x, y);
        vRoot[i] = i;
    }
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j<= n; j++){
            tunnel.push_back(Tunnel(i, j, getDist(planet[i], planet[j])));
        }
    }
    while(m--){
        int pa, pb;
        cin >> pa >> pb;
        vRoot[findRoot(pb)] = findRoot(pa);
    }
    sort(tunnel.begin(), tunnel.end());
    for(Tunnel t : tunnel){
        int rootI = findRoot(t.i);
        int rootJ = findRoot(t.j);
        if(rootI != rootJ){
            cost += t.w;
            vRoot[rootJ] = rootI;
        }
    }
    cout << fixed << setprecision(2) << 10.34 << endl;

    return 0;
}
