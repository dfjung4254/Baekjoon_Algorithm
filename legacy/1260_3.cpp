#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool matrix[1000][1000];
bool stopDfs = false;

void dfs(int init, vector<int> st, int targetSize){
    if(stopDfs){
        return;
    }
    st.push_back(init);
    if(targetSize == st.size()){
        stopDfs = true;
        for(auto it = st.begin(); it != st.end(); it++){
            cout << *it << " ";
        }
        cout << '\n';
        return;
    }
    //하위 노드 검색
    for(int i = 0; i < targetSize; i++){
        if(matrix[init-1][i] == true){
            bool flag = true;
            for(int j = 0; j < st.size(); j++){
                if(st[j] == i+1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                dfs(i+1, st, targetSize);
            }
        }
    }
}

void bfs(int init, queue<int> queue, int targetSize, bool check[]){
    queue.push(init);
    check[init] = true;
    cout << init << " ";
    while(!queue.empty()){
        int v = queue.front();
        queue.pop();
        for(int i = 0; i < targetSize; i++){
            if(matrix[v-1][i] == true && check[i+1] == false){
                cout << i+1 << " ";
                check[i+1] = true;
                queue.push(i+1);
            }
        }
    }
}

int main(){

    int n, m, v;
    cin >> n >> m >> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = false;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        matrix[a-1][b-1] = true;
        matrix[b-1][a-1] = true;
    }
    vector<int> mystack;
    dfs(v, mystack, n);
    queue<int> myqueue;
    bool check[n+1];
    bfs(v, myqueue, n, check);

    return 0;
}
