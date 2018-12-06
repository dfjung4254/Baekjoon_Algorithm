#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#define MAX 103
using namespace std;

struct Vertex{
    int x, y;
    vector<int> next;
};
Vertex vertex[MAX];
bool visited[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        for(int i = 1; i <= n+2; i++){
            vertex[i].next.clear();
            visited[i] = false;
        }
        cin >> vertex[1].x >> vertex[1].y;
        for(int i = 3; i <= n+2; i++){
            cin >> vertex[i].x >> vertex[i].y;
        }
        cin >> vertex[2].x >> vertex[2].y;
        for(int i = 1; i <= n+1; i++){
            for(int j = i+1; j <= n+2; j++){
                int dist = abs(vertex[i].x-vertex[j].x)+abs(vertex[i].y-vertex[j].y);
                if(dist <= 1000){
                    //possible
                    vertex[i].next.push_back(j);
                    vertex[j].next.push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while(!q.empty()){
            int curIdx = q.front();
            q.pop();
            for(int nIdx : vertex[curIdx].next){
                if(!visited[nIdx]){
                    visited[nIdx] = true;
                    q.push(nIdx);
                }
            }
        }
        if(visited[2]) cout << "happy" << '\n';
        else cout << "sad" << '\n';
    }
    return 0;
}