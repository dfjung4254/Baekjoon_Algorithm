#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*

    1. 각각 x 기준, y 기준으로 정렬해서 n-1 개의 간선 후보들을
    만들어낸다.
    2. 2*(n-1) 개의 간선을 우선순위 큐에 가중치 순서로 집어넣는다.
    3. 쿼리를 가중치가 작은 순서대로 돌린다.
    4. 각 쿼리의 가중치에 만족하는 정점들을 연결해준다.(union find)
    5. 만약 현재 쿼리의 가중치로 연결된 두개의 정점이 서로 루트가 같으면(연결상태)
    true, 아니면 false 를 입력해준다.

*/

int n, q;
struct Vertex{
    int idx;
    int x, y;
};
struct Edge{
    int weight;
    int from, to;
};
struct compEdge{
    bool operator()(const Edge &a, const Edge &b){
        return (a.weight > b.weight);
    }
};
struct Query{
    int idx, vA, vB, weight;
};

vector<Vertex> vertexSortedByX;
vector<Vertex> vertexSortedByY;
vector<Query> queries;
priority_queue<Edge, vector<Edge>, compEdge> edges;
/* 각 정점의 조상 정점을 저장 */
int vertexRoot[250001] = {0, };
/* 각 최종 조상 정점의 포함 노드 개수를 저장 */
int vertexRank[250001] = {0, };
bool queryRet[250001] = {false, };

int findRoot(int tar){
    if(vertexRoot[tar] == tar){
        return tar;
    }else{
        return vertexRoot[tar] = findRoot(vertexRoot[tar]);
    }
}

void merge(Edge curEdge){

    int rt_from = findRoot(curEdge.from);
    int rt_to = findRoot(curEdge.to);

    /* 이미 연결되어 있음 */
    if(rt_from == rt_to){
        return;
    }

    /* 개수가 작은 것을 더 많은 것에 편입 시킨다 */
    if(vertexRank[rt_from] > vertexRank[rt_to]){
        vertexRoot[rt_to] = rt_from;
        vertexRank[rt_from] += vertexRank[rt_to];
        vertexRank[rt_to] = 0;
    }else{
        vertexRoot[rt_from] = rt_to;
        vertexRank[rt_to] += vertexRank[rt_from];
        vertexRank[rt_from] = 0;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int _x, _y;
        cin >> _x >> _y;
        vertexSortedByX.push_back({i, _x, _y});
        vertexSortedByY.push_back({i, _x, _y});
        vertexRoot[i] = i;
        vertexRank[i] = 1;
    }
    sort(vertexSortedByX.begin(), vertexSortedByX.end(), [&](Vertex &a, Vertex &b){
        return (a.x < b.x);
    });
    sort(vertexSortedByY.begin(), vertexSortedByY.end(), [&](Vertex &a, Vertex &b){
        return (a.y < b.y);
    });

    /* 소트를 해서 x, y 각각 기준으로 비교함으로써 간선이 될 수 있는 후보명단을 n^2 이 아니라 2n 급으로 간추릴 수 있다.*/
    int vSize = vertexSortedByX.size();
    for(int i = 0; i < vSize-1; i++){
        Vertex from = vertexSortedByX[i];
        Vertex to = vertexSortedByX[i+1];
        int diff = abs(from.x - to.x);
        edges.push({diff, from.idx, to.idx});
    }
    for(int i = 0; i < vSize-1; i++){
        Vertex from = vertexSortedByY[i];
        Vertex to = vertexSortedByY[i+1];
        int diff = abs(from.y - to.y);
        edges.push({diff, from.idx, to.idx});
    }

    /* 쿼리 등록 */
    for(int i = 1; i <= q; i++){
        int a, b, w;
        cin >> a >> b >> w;
        queries.push_back({i, a, b, w});
    }
    /* 쿼리를 가중치 순으로 소트 */
    sort(queries.begin(), queries.end(), [&](Query &a, Query &b){
        return (a.weight < b.weight);
    });

    /* 쿼리(가중치 낮은 순으로) 돌면서 해당 weight 병합 및 결론 도출 */
    for(int i = 0; i < q; i++){

        Query query = queries[i];
        int target_weight = query.weight;

        /* 해당 weight 를 기준으로 만족하는 간선 모두 merge */
        /* 간선들은 이미 weight 를 기준으로 정렬되어 있다. */
        /* 또한 쿼리도 weight를 기준으로 정렬되어 있기 때문에 */
        /* 우선 순위 큐를 돌면서 중간에 빠져나오는 방식으로 구현가능하다 */
        while(!edges.empty()){
            
            Edge cur_edge = edges.top();
            int cur_weight = cur_edge.weight;
            if(cur_weight > target_weight){
                break;
            }
            /* 현재 간선을 이어 줌 */
            merge(cur_edge);
            edges.pop();
        }
        /* 해당 weight 기준 a, b 연결여부 확인 */
        int rtA = findRoot(query.vA);
        int rtB = findRoot(query.vB);
        queryRet[query.idx] = (rtA == rtB);
    }

    for(int i = 1; i <= q; i++){
        string ret = (queryRet[i]) ? "YES":"NO";
        cout << ret.c_str() << '\n';
    }

    return 0;
}