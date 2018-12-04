#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, m, k, cost = 0;
int vRoot[MAX] = {0, };
class Tunnel{
public:
    int i, j, w;
    Tunnel(int i = 0, int j = 0, int w = 0)
    :i(i), j(j), w(w) {}
    bool operator < (const Tunnel &t) const {
        return w < t.w;
    }
};
vector<Tunnel> tunnel;

int findRoot(int v){
    if(vRoot[v] == -1) return -1;
    else if(vRoot[v] == v) return v;
    return vRoot[v] = findRoot(vRoot[v]);
}

void kruskal(){
    sort(tunnel.begin(), tunnel.end());
    for(Tunnel t : tunnel){
        int rootI = findRoot(t.i);
        int rootJ = findRoot(t.j);
        if(rootI != rootJ){
            if(rootI == -1){
                vRoot[rootJ] = rootI;
            }else if(rootJ == -1){
                vRoot[rootI] = rootJ;
            }else{
                vRoot[rootJ] = rootI;
            }
            cost += t.w;
        }
    }
    cout << cost << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        vRoot[i] = i;
    }
    while(k--){
        int tp;
        cin >> tp;
        vRoot[tp] = -1;
    }
    while(m--){
        int i, j, w;
        cin >> i >> j >> w;
        tunnel.push_back(Tunnel(i, j, w));
    }
    kruskal();
    return 0;
}
