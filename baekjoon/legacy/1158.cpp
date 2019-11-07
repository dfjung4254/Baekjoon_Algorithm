#include <iostream>
#include <queue>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    cout << "<";
    bool flag = true;
    while(!q.empty()){
        for(int i = 0; i < m-1; i++){
            int tp = q.front();
            q.pop();
            q.push(tp);
        }
        if(flag){
           flag = false; 
        }else{
            cout << ", ";
        }
        cout << q.front();
        q.pop();
    }
    cout << ">" << '\n';
    return 0;
}