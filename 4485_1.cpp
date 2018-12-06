#include <iostream>
#include <queue>
#define MAX 126
#define INF 1000000000
using namespace std;

int matrix[MAX][MAX];
int dist[MAX][MAX];
//left top right down
int curx[] = {-1, 0, 1, 0};
int cury[] = {0, -1, 0, 1};
struct Vertex{
    int i, j, dist;
    bool operator < (const Vertex &v) const {
        return dist > v.dist;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 0;
    while(++tc){
        int n;
        cin >> n;
        if(n==0) break;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> matrix[i][j];
                dist[i][j] = INF;
            }
        }
        dist[1][1] = matrix[1][1];
        priority_queue<Vertex> pq;
        pq.push({1, 1, dist[1][1]});
        while(!pq.empty()){
            Vertex curVertex = pq.top();
            pq.pop();
            for(int dir = 0; dir < 4; dir++){
                int ni = curVertex.i + curx[dir];
                int nj = curVertex.j + cury[dir];
                if(ni < 1 || ni > n || nj < 1 || nj > n) continue;
                if(dist[ni][nj] > dist[curVertex.i][curVertex.j] + matrix[ni][nj]){
                    dist[ni][nj] = dist[curVertex.i][curVertex.j] + matrix[ni][nj];
                    pq.push({ni, nj, dist[ni][nj]});
                }
            }
        }
        cout << "Problem " << tc << ": " << dist[n][n] << '\n';
    }

    return 0;
}