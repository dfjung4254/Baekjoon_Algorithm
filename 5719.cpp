#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct Node
{
    // 최단거리를 구할 때 이전 노드인덱스를 저장함.
    vector<int> post;
    int index;
    int dist = INF;
    // weight, nextPoint, isValid
    vector<pair<int, pair<int, char>>> next;
    bool operator < (const Node &n) const{
        return dist > n.dist;
    }
};

Node nodes[501];
int start, finish;
priority_queue<Node> pq;
queue<Node> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }

        for (int i = 0; i < 501; i++)
        {
            nodes[i].index = i;
            nodes[i].post.clear();
            nodes[i].dist = INF;
            nodes[i].next.clear();
        }
        cin >> start >> finish;
        for (int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            nodes[u].next.push_back(make_pair(p, make_pair(v, true)));
        }
        // 먼저 다익스트라를 통해 최단 경로를 구한다.
        nodes[start].dist = 0;
        pq.push(nodes[start]);
        while(!pq.empty()){
            Node curNode = pq.top();
            pq.pop();
            for(pair<int, pair<int, char>> pa : curNode.next){
                if(nodes[pa.second.first].dist >= curNode.dist + pa.first){
                    if(nodes[pa.second.first].dist > curNode.dist + pa.first){
                        nodes[pa.second.first].post.clear();
                    }
                    nodes[pa.second.first].dist = curNode.dist + pa.first;
                    nodes[pa.second.first].post.push_back(curNode.index);
                    pq.push(nodes[pa.second.first]);
                }
            }
        }

        /* 최단경로 제거 bfs 사용 */
        // 현재 노드의 post노드의 next가 현재노드의 인덱스로 향하고 있으면 valid 를 false 로 준다.
        q.push(nodes[finish]);
        while(!q.empty()){
            Node curNode = q.front();
            q.pop();
            for(int idx : curNode.post){
                Node postNode = nodes[idx];
                int size = postNode.next.size();
                for (int i = 0; i < size; i++)
                {
                    pair<int, pair<int, char>> pa = postNode.next[i];
                    if(pa.second.first == curNode.index){
                        nodes[idx].next[i].second.second = false;
                    }
                }
                q.push(nodes[idx]);
            }
        }

        for (int i = 0; i < 501; i++)
        {
            nodes[i].post.clear();
            nodes[i].dist = INF;
        }

        nodes[start].dist = 0;
        pq.push(nodes[start]);
        while(!pq.empty()){
            Node curNode = pq.top();
            pq.pop();
            for(pair<int, pair<int, char>> pa : curNode.next){
                if(pa.second.second && nodes[pa.second.first].dist >= curNode.dist + pa.first){
                    nodes[pa.second.first].dist = curNode.dist + pa.first;
                    pq.push(nodes[pa.second.first]);
                }
            }
        }
        if(nodes[finish].dist >= INF){
            cout << -1 << '\n';
        }else{
            cout << nodes[finish].dist << '\n';
        }
    }

    return 0;
}