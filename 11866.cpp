#include <iostream>
#include <queue>
using namespace std;

int n, m;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        q.push(i+1);
    }
    int stack = 0;
    cout << "<";
    while(!q.empty()){
        int tp = q.front();
        q.pop();
        if(++stack <= m-1){
            q.push(tp);
        }else{
            cout << tp;
            stack = 0;
            if(!q.empty()){
                cout << ", ";
            }
        }
    }
    cout << ">";

    return 0;
}