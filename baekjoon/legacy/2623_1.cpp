#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
class Node{
public:
    int inDegree = 0;
    vector<int> next;
    Node(){}
};
Node node[1001];
vector<int> ret;

void topologySort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        //indegree가 0인 시작점을 먼저 찾아
        //queue에 넣는다
        if(node[i].inDegree == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        //q를 통해 topologySort 진행.
        //현재 노드를 제거함과 동시에 연결되어 있는 노드들의
        //inDegree도 제거해줘서 그래프의 연결을 해제시켜준다.
        int curIndex = q.front();
        ret.push_back(curIndex);
        q.pop();
        for(auto it = node[curIndex].next.begin(); it != node[curIndex].next.end(); it++){
            if(--node[*it].inDegree == 0){
                q.push(*it);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int c, d;
        cin >> c >> d;
        for(int j = 1; j <= c-1; j++){
            int e;
            cin >> e;
            //연결관계를 형성해준다.
            node[d].next.push_back(e);
            node[e].inDegree++;
            d = e;
        }
    }
    topologySort();
    if(ret.size() != n){
        //이경우 cycle이 돌아 topologySort가 완전히 이루어진 경우가 아니다.
        //Cycle이 돌아 inDegree가 0인 node를 q에 넣지 못하면서 n개의 결과node를
        //채우기 전에 q가 비어 먼저 while문을 빠져나온 경우이다.
        //정상적으로 cycle없이 DAG를 만족하면서 topologySort가 이루어졌다면
        //ret에는 정확히 n개의 node가 들어가야한다.
        cout << 0 << endl;
    }else{
        //정상적인 경우
        for(auto it = ret.begin(); it != ret.end(); it++){
            cout << *it << '\n';
        }
    }

    return 0;
}
