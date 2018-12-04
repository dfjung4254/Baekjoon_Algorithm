#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
class Node{
public:
    vector<int> next;
    int indegree = 0;
    Node(){}
};
Node node[1001];
vector<int> ans;

void topologySort(){

    queue<int> q;
    for(int i = 1; i <= n; i++){
        //indegree가 0인 node를 모두 q에 넣는다.
        if(node[i].indegree == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int tpIndex= q.front();
        ans.push_back(tpIndex);
        q.pop();
        for(auto it = node[tpIndex].next.begin(); it != node[tpIndex].next.end(); it++){
            if(--node[*it].indegree == 0){
                q.push(*it);
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int size, a;
        cin >> size >> a;
        for(int j = 0; j < size-1; j++){
            int b;
            cin >> b;
            node[a].next.push_back(b);
            node[b].indegree++;
            a = b;
        }
    }

    topologySort();
    if(ans.size() != n){
        cout << 0 << endl;
    }else{
        for(auto it = ans.begin(); it != ans.end(); it++){
            cout << *it << '\n';
        }
    }

    return 0;
}
