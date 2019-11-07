#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
double minCost = 0;
class Planet{
public:
    double x;
    double y;
    Planet(double x = 0, double y = 0):x(x), y(y) {}
};
Planet planet[101];
double getDist(Planet a, Planet b){
    return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}
class Tunnel{
public:
    int i;
    int j;
    double cost;
    Tunnel(int i, int j):i(i), j(j){
        cost = getDist(planet[i], planet[j]);
    }
    bool operator < (const Tunnel &t) const{
        return cost < t.cost;
    }
};
vector<Tunnel> tn;
int vRoot[101] = {0, };

int findRoot(int v){
    if(vRoot[v] == v) return v;
    return vRoot[v] = findRoot(vRoot[v]);
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
            tn.push_back(Tunnel(i, j));
        }
    }
    sort(tn.begin(), tn.end());
    for(Tunnel curT : tn){
        int rootI = findRoot(curT.i);
        int rootJ = findRoot(curT.j);
        if(rootI != rootJ){
            vRoot[rootJ] = rootI;
            minCost += curT.cost;
        }
    }
    cout << setprecision(3) << minCost << endl;

    return 0;
}
