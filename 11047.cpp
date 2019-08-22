#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
int n, k, cnt = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    int tp;
    for(int i = 0; i < n; i++){
        cin >> tp;
        st.push(tp);
    }

    while(!st.empty()){
        int cur = st.top();
        cnt += k / cur;
        k -= (k / cur) * cur;
        st.pop();
    }

    cout << cnt << '\n';

    return 0;

}