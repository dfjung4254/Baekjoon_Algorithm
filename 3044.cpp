#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define MOD 1000000000
using namespace std;

/*


    실패함....


*/

struct City{
    int degree = 0;
    int indegree = 0;
    //nIdx, useCount -- useCount는 indegree만큼 쓸수있다
    vector<pair<int, int>> next;
};
City city[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        city[a].next.push_back(make_pair(b, 0));
        city[b].indegree++;
    }
    queue<int> q;
    q.push(1);
    city[1].degree = 1;
    bool isCycle = false;
    while(!q.empty()){
        int cIdx = q.front();
        q.pop();
        for(auto it = city[cIdx].next.begin(); it != city[cIdx].next.end(); it++){
            const int nIdx = it->first;
            (it->second)++; //다리 사용량 증가
            if(it->second > city[cIdx].indegree && cIdx != 1){
                cout << cIdx << "/" << city[cIdx].indegree << "/" << it->second << '\n';
                cout << "inf" << '\n';
                return 0;
            }
            city[nIdx].degree++;
            city[nIdx].degree %= MOD;
            q.push(nIdx);
        }
    }
    if(isCycle) cout << "inf" << '\n';
    else cout << city[2].degree << '\n';

    return 0;
}