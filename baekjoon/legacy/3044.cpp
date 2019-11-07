#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001
#define MOD 1000000000
using namespace std;

/*

    실패함.

*/

struct City{
    int degree = 0, idx;
    vector<int> next;
};
City city[MAX];
bool visited[MAX];
bool finished[MAX];
vector<int> st;
int isCycle = 0;

void dfs(int cIdx, int goal){
    visited[cIdx] = true;
    st.push_back(cIdx);
    if(cIdx == goal){
        for(int idx : st){
            cout << idx << " ";
        }
        cout << '\n';
        st.pop_back();
        return;
    }
    for(int nIdx : city[cIdx].next){
        if(!visited[nIdx]){
            dfs(nIdx, goal);
            visited[nIdx] = false;
        }else{
            cout << "revisited : " << '\n'; 
        }
    }
    st.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        city[a].next.push_back(b);
    }
    dfs(1, 2);
    // while(!st.empty()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << '\n' << isCycle << '\n';

    return 0;
}