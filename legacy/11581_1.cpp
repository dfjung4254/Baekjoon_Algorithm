#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> node[101];
bool visited[101] = {false, };

bool isCycle(int init){
    vector<int> v;
    v.push_back(init);
    visited[init] = true;
    while(!v.empty()){
        int curIndex = v.back();
        //현재 인덱스에서 다음 인덱스를 찾는다
        bool flag = true;
        for(auto it = node[curIndex].begin(); it != node[curIndex].end(); it++){
            if(visited[*it]){
                //다음 노드가 이미 방문한 곳임
                //만약 이 *it 인덱스가 이미 stack(v)에 들어있다면 cycle 발생
                for(auto cy = v.begin(); cy != v.end(); cy++){
                    if(*cy == *it){
                        //cycle발생.
                        return true;
                    }
                }
            }else{
                //다음 노드로 dfs한다.
                visited[*it] = true;
                v.push_back(*it);
                flag = false;
                break;
            }
        }
        if(flag){
            //방문할 다음 노드가 없을 경우.
            v.pop_back();
        }
    }
    //여기까지 return true 로 안넘어가고 무사히
    //dfs가 수행되었으면 Cycle이 존재하지 않음.
    return false;

}

int main(){

    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int s;
        cin >> s;
        for(int j = 1; j <= s; j++){
            int link;
            cin >> link;
            node[i].push_back(link);
        }
    }

    if(isCycle(1)){
        cout << "CYCLE" << endl;
    }else{
        cout << "NO CYCLE" << endl;
    }

    return 0;
}
