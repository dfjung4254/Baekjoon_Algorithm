#include <iostream>
#include <vector>
#include <queue>
#define MAX 501
using namespace std;

struct Building{
    int buildTime, indegree, postTime = 0;
    vector<int> next;
};
Building building[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> building[i].buildTime;
        while(true){
            int post;
            cin >> post;
            if(post == -1) break;
            building[post].next.push_back(i);
            building[i].indegree++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(building[i].indegree == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curIdx = q.front();
        q.pop();
        for(int nIdx : building[curIdx].next){
            if(building[nIdx].postTime
                < building[curIdx].buildTime + building[curIdx].postTime){
                building[nIdx].postTime = building[curIdx].buildTime + building[curIdx].postTime;
                }
            if(--building[nIdx].indegree == 0){
                q.push(nIdx);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << building[i].buildTime+building[i].postTime << '\n';
    }


    return 0;
}