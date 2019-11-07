#include <iostream>
#include <queue>
#define MAX 126
#define INF 1000000000
using namespace std;

int matrix[MAX][MAX];
int dist[MAX][MAX];
// left, up, right, down
const int dirx[] = {-1, 0, 1, 0};
const int diry[] = {0, -1, 0, 1};
struct Vertex{
    int dist;
    pair<int, int> dir;
    bool operator < (const Vertex &v) const{
        return dist > v.dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 0;
    while (++tc) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                dist[i][j] = INF;
            }
        }
        dist[0][0] = matrix[0][0];
        priority_queue<Vertex> pq;
        pq.push({dist[0][0], make_pair(0, 0)});
        while (!pq.empty()) {
            Vertex curPoint = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int cx = curPoint.dir.first;
                int cy = curPoint.dir.second;
                int tx = cx + dirx[i];
                int ty = cy + diry[i];
                if (tx < 0 || tx > n - 1 || ty < 0 || ty > n - 1)
                    continue;
                if (dist[tx][ty] > dist[cx][cy] + matrix[tx][ty]) {
                    dist[tx][ty] = dist[cx][cy] + matrix[tx][ty];
                    pq.push({dist[tx][ty], make_pair(tx, ty)});
                }
            }
        }
        cout << "Problem " << tc << ": " << dist[n-1][n-1] << '\n';
    }
    return 0;
}