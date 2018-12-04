#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
class Edge{
public:
    int i;
    int j;
    int weight;
    bool operator<(const Edge &v) const {
        return weight < v.weight;
    }
    Edge(int i, int j, int w)
    :i(i), j(j), weight(w) {}
};
vector<Edge> edges;
int vRoot[1001] = {0, };
int mincost = 0;
int maxcost = 0;

int findRoot(int v){
    if(vRoot[v] == v){
        return v;
    }
    return vRoot[v] = findRoot(vRoot[v]);
}

void kruskal(){
    for(int i = 0; i <= n; i++){
        vRoot[i] = i;
    }
    sort(edges.begin(), edges.end());
    for(Edge e : edges){
        int rootI = findRoot(e.i);
        int rootJ = findRoot(e.j);
        if(rootI != rootJ){
            //no cycle - connect
            mincost += e.weight;
            vRoot[rootJ] = rootI;
        }
    }
    for(int i = 0; i <= n; i++){
        vRoot[i] = i;
    }
    vector<Edge>::reverse_iterator rit(edges.rbegin());
    for(;rit != edges.rend(); rit++){
        int rootI = findRoot(rit->i);
        int rootJ = findRoot(rit->j);
        if(rootI != rootJ){
            maxcost += rit->weight;
            vRoot[rootJ] = rootI;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    m++;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 1){
            c = 0;
        }else{
            c = 1;
        }
        edges.push_back(Edge(a, b, c));
    }
    kruskal();
    cout << (maxcost * maxcost) - (mincost * mincost) << endl;
    return 0;
}
