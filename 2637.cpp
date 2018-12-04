#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int n, m;
class Node{
public:
    int inDegree;
    vector<pair<int, int>> unitCosts; //first : unitNode / second : cost;
    vector<pair<int, int>> next; //first : nextNode / second : cost;
    Node(){
        inDegree = 0;
    }
};
Node node[101];
vector<int> unitNodes;

void topologySort(){
    //inDegree가 0인 시작점 찾음.
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(node[i].inDegree == 0){
            q.push(i);
            //indegree가 0인 기본부품은 unitCosts를 내 node 1개 가지고 있다.
            node[i].unitCosts.push_back(make_pair(i, 1));
            //기본부품의 index들.
            unitNodes.push_back(i);
        }
    }

    while(!q.empty()){
        int curIndex = q.front();
        //curIndex 에서 내가 가지고 있는 unitCosts를 next의
        //unitCosts에 뿌린다
        for(auto it = node[curIndex].next.begin(); it != node[curIndex].next.end(); it++){
            int nextIndex = it->first;
            int nextCost = it->second;
            for(auto it2 = node[curIndex].unitCosts.begin(); it2 != node[curIndex].unitCosts.end(); it2++){
                int mIndex = it2->first;
                int mCost = it2->second;
                node[nextIndex].unitCosts.push_back(make_pair(mIndex, mCost * nextCost));
            }
            if(--node[nextIndex].inDegree == 0){
                //항상 inDegree가 0이 되면 q에 넣어서 진행해준다.
                q.push(nextIndex);
            }
        }
        q.pop();
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int targetNode, unitNode, cost;
        cin >> targetNode >> unitNode >> cost;
        node[targetNode].inDegree++;
        node[unitNode].next.push_back(make_pair(targetNode, cost));
    }

    topologySort();
    int ret[n+1] = {0, };
    //ret배열에 각 결과들을 모두 담아 종합하여 출력한다.
    for(auto it = node[n].unitCosts.begin(); it != node[n].unitCosts.end(); it++){
        //cout << it->first << " " << it->second << endl;
        ret[it->first] += it->second;
    }
    for(auto it = unitNodes.begin(); it != unitNodes.end(); it++){
        cout << *it << " " << ret[*it] << '\n';
    }

    return 0;
}
