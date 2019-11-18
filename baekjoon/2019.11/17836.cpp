#include <iostream>
#include <queue>

using namespace std;

struct Point {
  int i;
  int j;
  bool hasGram;
};

int n, m, t;
int matrix[101][101];
bool visited[101][101] = {
    false,
};
bool visited_hasGram[101][101] = {
    false,
};
int dir_i[4] = {0, 1, 0, -1};
int dir_j[4] = {1, 0, -1, 0};
int ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> matrix[i][j];
    }
  }

  int limited = t + 1;

  queue<Point> q;
  q.push({1, 1, false});
  visited[1][1] = true;
  bool isFind = false;
  while (limited--) {
    int q_size = q.size();
    while (q_size--) {
      Point curPoint = q.front();
      q.pop();
      if (curPoint.i == n && curPoint.j == m) {
        isFind = true;
        break;
      }
      if (matrix[curPoint.i][curPoint.j] == 2) curPoint.hasGram = true;
      for (int dir = 0; dir < 4; dir++) {
        int next_i = curPoint.i + dir_i[dir];
        int next_j = curPoint.j + dir_j[dir];
        if (next_i < 1 || next_i > n || next_j < 1 || next_j > m) continue;
        if (curPoint.hasGram && visited_hasGram[next_i][next_j]) continue;
        if (!curPoint.hasGram &&
            (visited[next_i][next_j] || matrix[next_i][next_j] == 1))
          continue;
        if (curPoint.hasGram) {
          visited_hasGram[next_i][next_j] = true;
        } else {
          visited[next_i][next_j] = true;
        }
        q.push({next_i, next_j, curPoint.hasGram});
      }
    }
    if (isFind) break;
  }
  if (isFind) {
    cout << t - limited << '\n';
  } else {
    cout << "Fail" << '\n';
  }

  return 0;
}