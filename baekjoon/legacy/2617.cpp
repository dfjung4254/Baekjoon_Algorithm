#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
bool visited[100] = {false, };
int matrix[100][100] = {0, };
int flag;
//1 은 왼쪽이 더 큼
//-1 은 왼쪽이 더 작음
//0 은 관계를 모름.

int dfs(int init, int bigorsmall){
    fill(visited, visited+n+1, false);
    stack<int> st;
    st.push(init);
    visited[init] = true;
    int count = 1;
    while(!st.empty()){
        int cur = st.top();
        bool isf = true;
        for(int i = 1; i <= n; i++){
            if(visited[i] == false && matrix[cur][i] == bigorsmall){
                st.push(i);
                visited[i] = true;
                count++;
                isf = false;
                break;
            }
        }
        if(isf){
            st.pop();
        }

    }
    return count;
}

int main(){

    cin >> n >> m;
    flag = (n+1) / 2;
    for(int i = 0; i < m; i++){
        int big, small;
        cin >> big >> small;
        matrix[big][small] = 1;
        matrix[small][big] = -1;
    }
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(dfs(i, 1) > flag || dfs(i, -1) > flag){
            ret++;
            //cout << i << " : can't be middle" << endl;
        }
    }
    cout << ret << endl;

    return 0;
}
