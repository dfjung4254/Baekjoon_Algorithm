#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
class Edge{
public:
    int i;
    int j;
    int w;
    Edge(int i, int j, int w)
    :i(i), j(j), w(w) {}
    bool operator < (const Edge &e) const {
        return w < e.w;
    }
};
vector<Edge> edge;
int minCost = 0, maxCost = 0;
int vRoot[1001] = {0, };

void resetRoot(){
    for(int i = 0; i <= n; i++){
        vRoot[i] = i;
    }
}

int findRoot(int v){
    if(vRoot[v] == v) return v;
    return vRoot[v] = findRoot(vRoot[v]);
}

void kruskal(){
    sort(edge.begin(), edge.end());
    resetRoot();
    for(Edge e : edge){
        int rootI = findRoot(e.i);
        int rootJ = findRoot(e.j);
        if(rootI != rootJ){
            //no cycle - merge.
            vRoot[rootJ] = rootI;
            minCost += e.w;
        }
    }
    resetRoot();
    for(auto rit = edge.rbegin(); rit != edge.rend(); rit++){
        int rootI = findRoot(rit->i);
        int rootJ = findRoot(rit->j);
        if(rootI != rootJ){
            vRoot[rootJ] = rootI;
            maxCost += rit->w;
        }
    }
    cout << (maxCost * maxCost) - (minCost * minCost) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    m++;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0) c = 1;
        else c = 0;
        edge.push_back(Edge(a, b, c));
    }
    kruskal();

    return 0;
}
