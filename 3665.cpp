#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int inDegree = 0;
    bool next[501] = {false, };
};
vector<string> strRet;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int testCase;
    cin >> testCase;
    for(int tc = 1; tc <= testCase; tc++){
        int n;
        cin >> n;
        int nums[n+1];
        Node node[n+1];
        for(int i = 1; i <= n; i++){
            cin >> nums[i];
        }
        //작년 순위대로 DAG 그래프작성.
        for(int i = 1; i <= n-1; i++){
            for(int j = i+1; j <= n; j++){
                node[nums[i]].next[nums[j]] = true;
                node[nums[j]].inDegree++;
            }
        }
        // cout << "Node status-----------" << endl;
        // for(int i = 1; i <= n; i++){
        //     cout << "node : " << i << " / inDegree : " << node[i].inDegree << endl;
        //     cout << "next : ";
        //     for(int j = 1; j <= n; j++){
        //         if(node[i].next[j]){
        //             cout << j << " ";
        //         }
        //     }
        //     cout << endl;
        // }
        int cCase;
        cin >> cCase;
        //올해 바뀐순위정보 그래프 갱신.
        for(int i = 1; i <= cCase; i++){
            int a, b;
            cin >> a >> b;
            if(node[a].next[b] == true){
                //원래 a가 b보다 컸던경우
                node[a].next[b] = false;
                node[b].inDegree--;
                node[b].next[a] = true;
                node[a].inDegree++;
            }else{
                //원래 b가 a보다 컸던경우
                node[b].next[a] = false;
                node[a].inDegree--;
                node[a].next[b] = true;
                node[b].inDegree++;
            }
        }
        // cout << "Node Changed status-----------" << endl;
        // for(int i = 1; i <= n; i++){
        //     cout << "node : " << i << " / inDegree : " << node[i].inDegree << endl;
        //     cout << "next : ";
        //     for(int j = 1; j <= n; j++){
        //         if(node[i].next[j]){
        //             cout << j << " ";
        //         }
        //     }
        //     cout << endl;
        // }

        //갱신된 Node정보를 가지고 topologySort 실행
        //만약 한번 진행할때 inDegree가 0인 값이 두번나오면
        //확실한 순위를 찾을 수 없으므로 ? 출력
        //topolotySort를 마치고 사이즈가 안나올때(사이클이 돔)
        //()사이클이 돈다는 것은 크기관계가 먹고 먹힌다는 것이다 - IMPOSSIBLE)
        //위의 두 상황에 걸치지 않으면 정상 출력.
        queue<int> q;
        //첫 인풋정함
        bool flag = true;
        bool isOverlap = false;
        for(int i = 1; i <= n; i++){
            if(node[i].inDegree == 0){
                if(flag){
                    //cout << "start : " << i << endl;
                    q.push(i);
                    flag = false;
                }else{
                    //한번 초기 q를 설정했는데 또 inDegree가 0인 것이 있다.
                    //확실한 순위를 찾을 수 없음
                    strRet.push_back("?");
                    //cout << "?" << endl;
                    isOverlap = true;
                    break;
                }
            }
        }
        if(isOverlap){
            //중복된순간 그냥 다음으로 넘어감.
            continue;
        }
        vector<int> ret;
        while(!q.empty()){
            int curIndex = q.front();
            //cout << curIndex << " ";
            ret.push_back(curIndex);
            q.pop();
            flag = true;
            isOverlap = false;
            for(int i = 1; i <= n; i++){
                if(node[curIndex].next[i]){
                    if(--node[i].inDegree == 0){
                        if(flag){
                            q.push(i);
                            flag = false;
                        }else{
                            strRet.push_back("?");
                            //cout << "?" << endl;
                            isOverlap = true;
                            break;
                        }
                    }
                }
            }
            if(isOverlap){
                break;
            }
        }
        if(isOverlap){
            continue;
        }
        if(ret.size() == n){
            //정상 출력
            string tp = "";
            for(auto it = ret.begin(); it != ret.end(); it++){
                tp += to_string(*it)+" ";
                //cout << *it << " ";
            }
            strRet.push_back(tp);
            //cout << endl;
        }else{
            //Cycle이 돌아서 ret을 다 채우지 못함.
            //불가능함 모순발생
            strRet.push_back("IMPOSSIBLE");
            //cout << "IMPOSSIBLE" << endl;
        }

    }
    for(auto it = strRet.begin(); it != strRet.end(); it++){
        cout << *it << '\n';
    }
    return 0;
}
