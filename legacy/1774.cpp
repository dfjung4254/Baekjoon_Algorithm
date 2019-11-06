#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define MAX 1001
using namespace std;

int n, m;
double minCost = 0;
pair<int, int> planet[MAX];
class Tunnel{
public:
    int i, j;
    double weight;
    Tunnel(int i, int j, double w)
    :i(i), j(j), weight(w) {}
    bool operator < (const Tunnel &t) const {
        return weight < t.weight;
    }
};
vector<Tunnel> tunnel;
int vRoot[MAX] = {0, };

double getDist(pair<int, int> plA, pair<int, int> plB){
    return sqrt(pow(plA.first-plB.first,2)+pow(plA.second-plB.second,2));
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
        int a, b;
        cin >> a >> b;
        planet[i] = make_pair(a, b);
        vRoot[i] = i;
    }
    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            tunnel.push_back(Tunnel(i, j, getDist(planet[i], planet[j])));
        }
    }
    while(m--){
        int connectedA, connectedB;
        cin >> connectedA >> connectedB;
        vRoot[findRoot(connectedB)] = findRoot(connectedA);
    }
    sort(tunnel.begin(), tunnel.end());
    for(Tunnel t : tunnel){
        int rootI = findRoot(t.i);
        int rootJ = findRoot(t.j);
        if(rootI != rootJ){
            minCost += t.weight;
            vRoot[rootJ] = rootI;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << minCost << endl;

    return 0;
}
