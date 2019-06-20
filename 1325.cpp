#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int inDegree = 0;
    vector<int> nextIdx;
};

int n, m;
Node nodes[10001];
bool visited[10001];
queue<int> q;
int maxCnt = -1;
vector<int> ans;

void bfs(int thisIdx)
{

    /* visited 초기화 */
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }

    /* bfs 탐색하면서 해킹가능한 갯수 카운팅 */
    int cnt = 0;
    q.push(thisIdx);
    visited[thisIdx] = true;
    while (!q.empty())
    {
        int curIdx = q.front();
        cnt++;
        q.pop();
        int nextSize = nodes[curIdx].nextIdx.size();
        for (int i = 0; i < nextSize; i++)
        {
            int nextIdx = nodes[curIdx].nextIdx[i];
            if (!visited[nextIdx])
            {
                visited[nextIdx] = true;
                q.push(nextIdx);
            }
        }
    }

    /* cnt 를 현재 최고 idx와 비교한다. */
    if (cnt > maxCnt)
    {
        /* 현재 답에 들어있는 vector를 초기화 하고 새로운 idx로 갱신 */
        ans.clear();
        maxCnt = cnt;
        ans.push_back(thisIdx);
    }
    else if (cnt == maxCnt)
    {
        /* 현재 답이랑 같으므로 vector에 추가해준다. */
        ans.push_back(thisIdx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].inDegree++;
        nodes[b].nextIdx.push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }

    sort(ans.begin(), ans.end());
    for(int idx : ans)
    {
        cout << idx << " ";
    }
    cout << '\n';

    return 0;
}