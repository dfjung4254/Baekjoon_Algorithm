#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int testCase;

class Node{
public:
    int inDegree;
    int buildTime;
    vector<int> next;
    vector<int> before;
    Node(){
        buildTime = 0;
        inDegree = 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin >> testCase;
    int ret[testCase] = {0, };
    for(int tcase = 0; tcase < testCase; tcase++){
        int n, k, target;
        cin >> n >> k;
        Node node[n+1];
        for(int i = 1; i <= n; i++){
            cin >> node[i].buildTime;
        }
        for(int i = 1; i <= k; i++){
            int a, b;
            cin >> a >> b;
            node[a].next.push_back(b);
            node[b].inDegree++;
            node[b].before.push_back(a);
        }
        cin >> target;

        queue<int> q;
        //시작점 찾기
        for(int i = 1; i <= n; i++){
            if(node[i].inDegree == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curIndex = q.front();
            q.pop();
            for(auto it = node[curIndex].next.begin(); it != node[curIndex].next.end(); it++){
                if(--node[*it].inDegree == 0){
                    //다음 노드의 inDegree를 깎은것이 0이면 q에 넣음
                    q.push(*it);
                }
            }
            //현재 노드는 이전노드의 buildTime중 가장 큰시간에 자신의 buildTime을 더함.
            if(node[curIndex].before.size() != 0){
                int maxIndex = -1;
                int maxTime = -1;
                for(int i = 0; i < node[curIndex].before.size(); i++){
                    int index = node[curIndex].before[i];
                    if(node[index].buildTime > maxTime){
                        maxIndex = index;
                        maxTime = node[index].buildTime;
                    }
                }
                node[curIndex].buildTime += node[maxIndex].buildTime;
            }
        }
        //구해진 건문들 답을 배열에 넣음.
        ret[tcase] = node[target].buildTime;

    }

    for(int i = 0; i < testCase; i++){
        cout << ret[i] << '\n';
    }

    return 0;
}
