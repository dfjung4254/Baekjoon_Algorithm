#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define MAX 100001
#define INF 987654321
using namespace std;

int n, locA, locB;
struct Room{
    vector<pair<int, int>> next;
};
Room rooms[MAX];
queue<int> q;
stack<pair<int, int>> st;
bool visited[MAX];

void bfs(int start, int targ){
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        Room cur = rooms[q.front()];
        q.pop();
        for(pair<int, int> pa : cur.next){
            if(!visited[pa.second]){
                q.push(pa.second);
                st.push(make_pair(pa.second, pa.first));
                visited[pa.second] = true;
            }
        }
    }
    int sum = 0;
    int max = 0;
    int curt = targ;
    while(!st.empty()){
        int idx = st.top().first;
        int width = st.top().second;
        if(idx == targ){
            sum += width;
            max = width;
        }
        for(pair<int, int> pa : rooms[curt].next){
            if(pa.second == idx){
                sum += width;
                if(max < width){
                    max = width;
                }
                curt = idx;
                break;
            }
        }
        st.pop();
    }
    cout << sum-max << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> locA >> locB;
    for(int i = 0; i < n-1; i++){
        int ti, tj, tw;
        cin >> ti >> tj >> tw;
        rooms[ti].next.push_back(make_pair(tw, tj));
        rooms[tj].next.push_back(make_pair(tw, ti));
    }
    bfs(locA, locB);

    return 0;
}