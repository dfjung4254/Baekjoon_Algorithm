#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
class Node{
public:
    vector<int> next;
    int indegree = 0;
    Node(){

    }
};

void topologySort(Node node[]){
    //indegree가 0인 숫자만 q에 집어넣는다.
    queue<int> q;
    //start 점 찾아서 q에 넣기
    for(int i = 1; i <= n; i++){
        if(node[i].indegree == 0){
            q.push(i);
            //cout << i << " : q input" << endl;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for(auto it = node[cur].next.begin(); it != node[cur].next.end(); it++){
            //현재 노드와 연결된 모든 하위 노드의 indegree를 줄여주고 indegree가 0이면
            //q에 넣어줌.
            int tpIndegree = --node[*it].indegree;
            if(tpIndegree == 0){
                q.push(*it);
                //cout << *it << " : q input" << endl;
            }
        }
    }

}

int main(){

    cin >> n >> m;
    Node node[n+1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        node[a].next.push_back(b);
        node[b].indegree++;
    }
    topologySort(node);

    return 0;
}
