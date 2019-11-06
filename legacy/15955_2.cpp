#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
struct Vertex{
    int idx, x, y;
};
struct Edge{
    int v1, v2, weight;
};
struct Query{
    int idx, v1, v2, weight;
};
vector<Vertex> vertex_x;
vector<Vertex> vertex_y;
vector<Edge> edges;
vector<Query> queries;
int check_root[250001];
int check_rank[250001];
bool ret[250001] = {false, };

int findRoot(int target){
    return (check_root[target] == target) ?
    target:check_root[target] = findRoot(check_root[target]);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        vertex_x.push_back({i, x, y});
        vertex_y.push_back({i, x, y});
        check_root[i] = i;
        check_rank[i] = 1;
    }
    sort(vertex_x.begin(), vertex_x.end(), [](Vertex &a, Vertex &b)->bool{
        return (a.x < b.x);
    });
    sort(vertex_y.begin(), vertex_y.end(), [](Vertex &a, Vertex &b)->bool{
        return (a.y < b.y);
    });
    for(int i = 0; i < n-1; i++){
        Vertex v1 = vertex_x[i];
        Vertex v2 = vertex_x[i+1];
        edges.push_back({v1.idx, v2.idx, v2.x-v1.x});
    }
    for(int i = 0; i < n-1; i++){
        Vertex v1 = vertex_y[i];
        Vertex v2 = vertex_y[i+1];
        edges.push_back({v1.idx, v2.idx, v2.y-v1.y});
    }
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)->bool{
        return (a.weight < b.weight);
    });
    for(int i = 0; i < q; i++){
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        queries.push_back({i, v1, v2, weight});
    }
    sort(queries.begin(), queries.end(), [](Query &a, Query &b)->bool{
        return (a.weight < b.weight);
    });
    auto edge_it = edges.begin();
    for(auto it = queries.begin(); it != queries.end(); it++){
        Query thisQuery = *it;
        int thisWeight = thisQuery.weight;
        while(edge_it != edges.end()){
            int edgesWeight = edge_it->weight;
            if(edgesWeight > thisWeight){
                break;
            }
            /* merge */
            int v1_root = findRoot(edge_it->v1);
            int v2_root = findRoot(edge_it->v2);
            if(v1_root != v2_root){
                if(check_rank[v1_root] < check_rank[v2_root]){
                    check_root[v1_root] = v2_root;
                    check_rank[v1_root] = 1;
                    check_rank[v2_root]++;
                }else{
                    check_root[v2_root] = v1_root;
                    check_rank[v2_root] = 1;
                    check_rank[v1_root]++;
                }
            }
            edge_it++;
        }
        ret[thisQuery.idx] = (findRoot(thisQuery.v1) == findRoot(thisQuery.v2));
    }

    for(int i = 0; i < q; i++){
        string stRet = (ret[i]) ? "YES":"NO";
        cout << stRet.c_str() << '\n';
    }

    return 0;
}