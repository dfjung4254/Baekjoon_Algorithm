#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct Edge{
    int p1, p2, weight;
};
vector<Edge> edges;
int planet_root[1001];
int planet_rank[1001];
int_fast64_t ret = 0;

int findRoot(int target){
    return (planet_root[target] == target) ?
    target:planet_root[target] = findRoot(planet_root[target]);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        planet_root[i] = i;
        planet_rank[i] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int w;
            cin >> w;
            if(i < j){
                edges.push_back({i, j, w});
            }
        }
    }
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)->bool{
        return (a.weight < b.weight);
    });

    for(auto it = edges.begin(); it != edges.end(); it++){
        Edge cur_edge = *it;
        int root_p1 = findRoot(cur_edge.p1);
        int root_p2 = findRoot(cur_edge.p2);
        if(root_p1 != root_p2){
            ret += cur_edge.weight;
            if(planet_rank[root_p1] < planet_rank[root_p2]){
                planet_root[root_p1] = root_p2;
                planet_rank[root_p2] += planet_rank[root_p1];
                if(planet_rank[root_p2] == n){
                    break;
                }
            }else{
                planet_root[root_p2] = root_p1;
                planet_rank[root_p1] += planet_rank[root_p2];
                if(planet_rank[root_p1] == n){
                    break;
                }
            }
        }
    }

    cout << ret << '\n';

    return 0;
}