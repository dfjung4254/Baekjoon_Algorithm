#include <iostream>
#include <string>
#include <stack>
#include <string.h>
#define ll long long
using namespace std;

ll height[100000];
stack<ll> st;
ll max_size = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        memset(height, 0, sizeof(height));
        max_size = 0;
        for (int i = 0; i < n; i++){
            cin >> height[i];
        }
        /* 돌면서 stack에 넣을 지 말지를 정한다. */
        for (int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] > height[i]){
                ll ht = height[st.top()];
                st.pop();
                ll wt = i;
                if(!st.empty()){
                    wt = (i - st.top() - 1);
                }
                ll size = ht * wt;
                if(max_size  < size){
                    max_size = size;
                }
            }
            st.push(i);
        }
        while (!st.empty())
        {
            ll ht = height[st.top()];
            st.pop();
            ll wt = n;
            if (!st.empty())
            {
                wt = (n - st.top() - 1);
            }
            ll size = ht * wt;
            if (max_size < size)
            {
                max_size = size;
            }
        }
        cout << max_size << '\n';
    }


    return 0;
}