#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

struct Problem{
    int idx, indegree = 0;
    vector<int> next;
};
Problem problem[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        problem[i].idx = i;
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        problem[a].next.push_back(b);
        problem[b].indegree++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++){
        if(problem[i].indegree == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int idx = pq.top();
        cout << idx << " ";
        pq.pop();
        for(int nIdx : problem[idx].next){
            if(--problem[nIdx].indegree == 0){
                pq.push(nIdx);
            }
        }
    }

    return 0;
}