#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
#define MAX 101
#define INF 1000000000
using namespace std;

struct Vertex{
    bool isCannon = true;
    double i, j, dist = INF;
    vector<pair<double, int>> next;
    bool operator < (const Vertex &v) const {
        return dist > v.dist;
    }
};
Vertex vertex[MAX];

double getDist(Vertex v1, Vertex v2){
    double dt = sqrt(pow(v1.i-v2.i,2) + pow(v1.j-v2.j,2));
    if(dt >= 30 && v1.isCannon){
        //cannon
        return abs(dt-50)/5 + 2;
    }else{
        //walk
        return dt/5;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vertex[1].dist = 0;
    vertex[1].isCannon = false;
    vertex[2].isCannon = false;
    cin >> vertex[1].i >> vertex[1].j;
    cin >> vertex[2].i >> vertex[2].j;
    int m;
    cin >> m;
    for(int i = 3; i <= m+2; i++){
        cin >> vertex[i].i >> vertex[i].j;
    }
    for(int i = 1; i <= m+2; i++){
        for(int j = 1; j <= m+2; j++){
            if(i==j) continue;
            vertex[i].next.push_back(make_pair(getDist(vertex[i], vertex[j]), j));
        }
    }
    priority_queue<Vertex> pq;
    pq.push(vertex[1]);
    while(!pq.empty()){
        Vertex curVertex = pq.top();
        pq.pop();
        for(pair<double, int> pa : curVertex.next){
            double w = pa.first;
            int nIdx = pa.second;
            if(vertex[nIdx].dist > curVertex.dist + w){
                vertex[nIdx].dist = curVertex.dist + w;
                pq.push(vertex[nIdx]);
            }
        }
    }
    cout << fixed << setprecision(3) << vertex[2].dist << '\n';

    return 0;
}