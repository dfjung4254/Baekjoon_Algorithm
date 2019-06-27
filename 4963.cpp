#include <iostream>
#include <queue>
using namespace std;

int w, h;
int matrix[51][51];
bool visited[51][51] = {
    false,
};
queue<pair<int, int>> q;
int ans;
/* 시계방향 회전 */
const int dir_i[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dir_j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        ans = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> matrix[i][j];
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visited[i][j] && matrix[i][j] == 1)
                {
                    ans++;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    while (!q.empty())
                    {
                        pair<int, int> curPoint = q.front();
                        q.pop();
                        for (int dir = 0; dir < 8; dir++)
                        {
                            int next_i = curPoint.first + dir_i[dir];
                            int next_j = curPoint.second + dir_j[dir];
                            if(next_i < 0 || next_i >= h || next_j < 0 || next_j >= w) continue;
                            if (!visited[next_i][next_j] && matrix[next_i][next_j] == 1)
                            {
                                visited[next_i][next_j] = true;
                                q.push(make_pair(next_i, next_j));
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}