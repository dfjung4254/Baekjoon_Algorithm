#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int n, m;
deque<int> dq;
queue<int> findIndex;

int searchIndex(int targetIdx){
    int idx = 1;
    for(int i : dq){
        if(i == targetIdx){
            break;
        }
        idx++;
    }
    return idx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }
    for(int i = 0; i < m; i++){
        int tp;
        cin >> tp;
        findIndex.push(tp);
    }
    int ret = 0;
    while(!findIndex.empty()){
        int targetIdx = findIndex.front();
        findIndex.pop();
        int curLocation = searchIndex(targetIdx);
        if(curLocation != 1){
            int mid = (dq.size()+1) / 2;
            if(curLocation <= mid){
                // 2번 수행
                while(--curLocation){
                    int tp = dq.front();
                    dq.pop_front();
                    dq.push_back(tp);
                    ret++;
                }
            }else{
                // 3번 수행
                int cnt = dq.size() - curLocation + 1;
                while(cnt--){
                    int tp = dq.back();
                    dq.pop_back();
                    dq.push_front(tp);
                    ret++;
                }
            }
        }
        dq.pop_front();
    }
    cout << ret << '\n';

    return 0;
}