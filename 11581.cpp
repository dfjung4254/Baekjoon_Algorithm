#include <iostream>
#include <vector>
using namespace std;

/*

    그래프의 CYCLE검사하기.
    DFS.
    Stack을 이용한 DFS중 만약 visited가 true인 점을 만났을때
    그 점이 현재 Stack에 들어있나 검사.
    들어있으면 CYCLE이 도는 것.

*/

int n;
class Node{
public:
    int inDegree = 0;
    vector<int> next;
    Node(){}
};
Node node[101];
bool visited[101] = {false, };

bool isCycle(int init){
    vector<int> st;
    st.push_back(init);
    visited[init] = true;
    bool ret = false;
    while(!st.empty()){
        int curIndex = st.back();
        //cout << curIndex << " : visited" << endl;
        //다음 노드를 찾는다
        bool flag = true;
        for(auto it = node[curIndex].next.begin(); it != node[curIndex].next.end(); it++){
            if(visited[*it] == true){
                //만약 그 *it가 이미 stack에 존재한다면 cycle임
                for(auto cy = st.begin(); cy != st.end(); cy++){
                    if(*cy == *it){
                        ret = true;
                        return ret;
                    }
                }
            }else{
                visited[*it] = true;
                st.push_back(*it);
                flag = false;
                break;
            }
        }
        if(flag){
            st.pop_back();
        }
    }
    return ret;

}

int main(){

    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int s;
        cin >> s;
        for(int j = 1; j <= s; j++){
            int nextIndex;
            cin >> nextIndex;
            node[i].next.push_back(nextIndex);
            node[nextIndex].inDegree++;
        }
    }
    if(isCycle(1)){
        cout << "CYCLE" << endl;
    }else{
        cout << "NO CYCLE" << endl;
    }
    return 0;
}
