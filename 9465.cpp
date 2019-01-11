#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 100001
using namespace std;

bool visited[2][MAX];
vector<pair<int, pair<int, int>>> v;

bool comp(pair<int, pair<int, int>> pa, pair<int, pair<int, int>> pb){
    return pa.first > pb.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        memset(visited, false, sizeof(visited));
        v.clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int tp;
            cin >> tp;
            v.push_back(make_pair(tp, make_pair(0, i)));
        }
        for(int i = 0; i < n; i++){
            int tp;
            cin >> tp;
            v.push_back(make_pair(tp, make_pair(1, i)));
        }
        sort(v.begin(), v.end(), comp);
        int sum = 0;
        for(pair<int, pair<int, int>> pa : v){
            int weight = pa.first;
            int i = pa.second.first;
            int j = pa.second.second;
            if(!visited[i][j]){
                visited[i][j] = true;
                if(j > 0){
                    visited[i][j-1] = true;
                }
                if(j < n-1){
                    visited[i][j+1] = true;
                }
                sum += weight;
                if(i == 0){
                    visited[1][j] = true;
                }else{
                    visited[0][j] = true;
                }
            }
        }
        cout << sum << '\n';
    }

    return 0;
}