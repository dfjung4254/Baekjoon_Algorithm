#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> *node;
bool visited[1001];
int cost = 0;

void prim(){

    queue<int> q;
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
    q.push(1);
    while(!q.empty()){
        int curIndex = q.front();
        //cout << curIndex << " : visited" << endl;
        visited[curIndex] = true;
        q.pop();
        for(auto it = node[curIndex].begin(); it != node[curIndex].end(); it++){
            int targetIndex = (*it).second;
            int targetWeight = (*it).first;
            if(visited[targetIndex] == false){
                pq.push(make_pair(targetWeight, targetIndex));
            }
        }
        while(!pq.empty()){
            if(!visited[pq.top().second]){
                q.push(pq.top().second);
                cost += pq.top().first;
                pq.pop();
                break;
            }else{
                pq.pop();
            }
        }

    }

}

int main(){
    fill(visited, visited+1001, false);
    cin >> n;
    node = new vector<pair<int, int>>[n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int weight;
            cin >> weight;
            if(i < j){
                node[i].push_back(make_pair(weight, j));
                node[j].push_back(make_pair(weight, i));
            }
        }
    }
    prim();
    cout << cost << endl;
}
