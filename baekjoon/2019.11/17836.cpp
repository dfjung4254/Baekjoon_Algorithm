#include <iostream>
#include <queue>
using namespace std;

int matrix[101][101];
int visited[101][101] = {
    0,
};
int dir_i[4] = {0, 1, 0, -1};
int dir_j[4] = {1, 0, -1, 0};
int n, m, t;

struct Point {
  int i;
  int j;
  int dist;
  bool hasGram;
};

queue<Point> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> matrix[i][j];
    }
  }

  q.push({1, 1, 0, false});
  while (!q.empty()) {
    Point curPoint = q.front();
    q.pop();
    for (int dIdx = 0; dIdx < 4; dIdx++) {
      int next_i = curPoint.i + dir_i[dIdx];
      int next_j = curPoint.j + dir_j[dIdx];
      if (next_i < 1 || next_i > n || next_j < 1 || next_j > m ||
          visited[next_i][next_j] != 0)
        continue;
      if (matrix[next_i][next_j] == 1 && !curPoint.hasGram) continue;
      visited[next_i][next_j] = curPoint.dist + 1;
      Point nextPoint;
      nextPoint.i = next_i;
      nextPoint.j = next_j;
      nextPoint.dist = curPoint.dist + 1;
      nextPoint.hasGram =
          (matrix[next_i][next_j] == 1) ? false : nextPoint.hasGram;
      nextPoint.hasGram =
          (matrix[next_i][next_j] == 2) ? true : nextPoint.hasGram;
      q.push(nextPoint);
    }
  }

  if(visited[n][m] == 0){
    cout << "Fail" << '\n';
  }else{
    cout << visited[n][m] << '\n';
  }

  return 0;
}