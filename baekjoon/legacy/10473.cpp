#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#define MAX 103
#define INF 2000000000
using namespace std;

struct Point{
    bool isBomb = true;
    double x, y, dist = INF;
    vector<pair<double, int>> next;
    bool operator < (const Point &p) const {
        return dist > p.dist;
    }
};
int n;
//start idx1 , end idx2
Point point[MAX];

double calTime(Point p1, Point p2){
    double dist = sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y, 2));
    if(p1.isBomb && dist >= 30){
        return abs(dist-50)/5 + 2;
    }else{
        return dist/5;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    point[1].isBomb = false;
    point[2].isBomb = false;
    cin >> point[1].x >> point[1].y >> point[2].x >> point[2].y;
    cin >> n;
    for(int i = 3; i < n+3; i++){
        cin >>  point[i].x >> point[i].y;
    }
    for(int i = 1; i < n+2; i++){
        for(int j = i+1; j < n+3; j++){
            point[i].next.push_back(make_pair(calTime(point[i], point[j]), j));
            point[j].next.push_back(make_pair(calTime(point[j], point[i]), i));
        }
    }
    priority_queue<Point> pq;
    point[1].dist = 0;
    pq.push(point[1]);
    while(!pq.empty()){
        Point curPoint = pq.top();
        pq.pop();
        for(pair<double, int> pa : curPoint.next){
            double weight = pa.first;
            int idx = pa.second;
            if(point[idx].dist > curPoint.dist + weight){
                point[idx].dist = curPoint.dist + weight;
                pq.push(point[idx]);
            }
        }
    }
    cout << fixed << setprecision(6) << point[2].dist << '\n';

    return 0;
}