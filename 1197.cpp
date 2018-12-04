#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int v, e;
class Edge{
public:
    int i = 0;
    int j = 0;
    int weight = 0;
    bool operator<(const Edge &v) const{
        return weight < v.weight;
    }
    Edge(int i = 0, int j = 0, int weight = 0)
    :i(i), j(j), weight(weight) {}
};
int vRoot[10001] = {0, };
vector<Edge> edges;
int cost = 0;

int findRoot(int v){
    if(vRoot[v] == v){
        return v;
    }
    return vRoot[v] = findRoot(vRoot[v]);
}

void kruskal(){
    //sort부터 한다 weight 오름차순으로
    //각 노드의 루트를 정의해준다
    sort(edges.begin(), edges.end());
    for(Edge it : edges){
        //현재 간선을 놓을때 cycle이 발생하나 여부 확인
        //-> 노드 i 와 노드 j 의 각 뿌리가 같으면 cycle 발생(이미 연결되어있다)
        //-> 각 뿌리가 다르면 연결해도 됨.
        int rootI = findRoot(it.i);
        int rootJ = findRoot(it.j);
        if(rootI != rootJ){
            //union find 연결.
            //서로의 뿌리끼리 연결해준다.
            vRoot[rootJ] = rootI;
            cost += it.weight;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> e;
    for(int i = 1; i <= v; i++){
        vRoot[i] = i;
    }
    while(e--){
        int i, j, w;
        cin >> i >> j >> w;
        edges.push_back(Edge(i, j, w));
    }

    kruskal();
    cout << cost << endl;

    return 0;
}
