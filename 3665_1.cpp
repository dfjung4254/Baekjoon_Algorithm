#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int inDegree = 0;
    bool next[501] = {false, };
    Node(){}
};

void topologySort(Node node[], int n){
    queue<int> q;
    vector<int> ret;
    for(int i = 1; i <= n; i++){
        if(node[i].inDegree == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        if(q.size() > 1){
            //큐에 push가 한번에 두번이상 되었음 -> 위상정렬 케이스가 여러개라는 소리
            //확실하게 순위를 찾을수 없음
            cout << "?" << endl;
            return;
        }
        int curIndex = q.front();
        ret.push_back(curIndex);
        q.pop();
        //현재 연결되어있는 하위노드 inDegree제거
        for(int i = 1; i <= n; i++){
            if(node[curIndex].next[i]){
                if(--node[i].inDegree == 0){
                    q.push(i);
                }
            }
        }
    }
    if(ret.size() == n){
        for(int it : ret){
            cout << it << " ";
        }
        cout << '\n';
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(){

    int tCase;
    cin >> tCase;
    while(tCase--){
        int n;
        cin >> n;
        int nums[n+1];
        Node node[n+1];
        for(int i = 1; i <= n; i++){
            cin >> nums[i];
        }
        for(int i = 1; i <= n-1; i++){
            for(int j = i+1; j <= n; j++){
                //1등은 2,3,4,5등 모두보다 무조건 앞에 위치
                //2등은 3,4,5등 모두보다 무조건 앞에위치 -> 전부 위상설정해줘야한다.
                node[nums[i]].next[nums[j]] = true;
                node[nums[j]].inDegree++;
            }
        }
        int ch;
        cin >> ch;
        while(ch--){
            int a, b;
            cin >> a >> b;
            if(!node[a].next[b]){
                int tmp = a;
                a = b;
                b = tmp;
            }
            //노드 a가 노드 b보다 더 큰경우 방향수정
            //해제
            node[a].next[b] = false;
            node[b].inDegree--;
            //역방향설정
            node[b].next[a] = true;
            node[a].inDegree++;
        }
        //수정된 정보로 위상정렬한다.
        topologySort(node, n);
    }

    return 0;
}
