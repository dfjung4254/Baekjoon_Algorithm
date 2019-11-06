#include <iostream>
#include <vector>
#include <queue>
#define MAX 501
using namespace std;

int n;
struct Build{
    int idx, buildTime, indegree = 0;
    int postBuildTime = 0;
    vector<int> next;
};
Build build[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        build[i].idx = i;
        cin >> build[i].buildTime;
        while(true){
            int postBuild;
            cin >> postBuild;
            if(postBuild == -1) break;
            build[postBuild].next.push_back(i);
            build[i].indegree++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(build[i].indegree == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        for(int nIdx : build[idx].next){
            if(build[nIdx].postBuildTime < build[idx].buildTime + build[idx].postBuildTime){
                build[nIdx].postBuildTime = build[idx].buildTime + build[idx].postBuildTime;
            }
            if(--build[nIdx].indegree == 0){
                q.push(build[nIdx].idx);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << build[i].buildTime+build[i].postBuildTime << '\n';
    }

    return 0;
}