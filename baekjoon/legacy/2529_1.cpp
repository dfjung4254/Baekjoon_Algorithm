#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Num{
    int idx, indegree = 0;
    vector<int> next;
};
Num num[10];
Num minNum[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 9; i >= 10-n; i--){ 
        char ch;
        int min_i = 9-i;
        cin >> ch;
        if(ch == '<'){
            num[i].indegree++;
            num[i-1].next.push_back(i);
            minNum[min_i].next.push_back(min_i+1);
            minNum[min_i+1].indegree++;
        }else{
            num[i].next.push_back(i-1);
            num[i-1].indegree++;
            minNum[min_i].indegree++;
            minNum[min_i+1].next.push_back(min_i);
        }
    }
    priority_queue<int> pq;
    for(int i = 9; i >= 9-n; i--){
        if(num[i].indegree == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int idx = pq.top();
        cout << idx;
        pq.pop();
        for(int nIdx : num[idx].next){
            if(--num[nIdx].indegree == 0){
                pq.push(nIdx);
            }
        }
    }
    cout << '\n';
    priority_queue<int, vector<int>, greater<int>> pq1;
    for(int i = 9; i >= 9-n ; i--){
        int minI = 9-i;
        if(minNum[minI].indegree == 0){
            pq1.push(minI);
        }
    }
    while(!pq1.empty()){
        int idx = pq1.top();
        cout << idx;
        pq1.pop();
        for(int nIdx : minNum[idx].next){
            if(--minNum[nIdx].indegree == 0){
                pq1.push(nIdx);
            }
        }
    }

    return 0;
}