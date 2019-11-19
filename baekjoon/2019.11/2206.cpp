#include <iostream>
#include <queue>

using namespace std;

struct Point {
  int i;
  int j;
  bool isWallPassed;
};
int matrix[1001][1001];
bool visited[1001][1001] = {
    false,
};
bool visited_broken[1001][1001] = {
    false,
};
int dir_i[4] = {0, 1, 0, -1};
int dir_j[4] = {1, 0, -1, 0};
int n, m;
queue<Point> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      cin >> ch;
      matrix[i][j] = ch - '0';
    }
  }

  int turn = 0;
  bool isFind = false;
  q.push({1, 1, false});
  visited[1][1] = true;
  while (!q.empty()) {
    turn++;
    int q_size = q.size();
    while (q_size--) {
      Point cur_point = q.front();
      q.pop();
      if (matrix[cur_point.i][cur_point.j] == 1) {
        cur_point.isWallPassed = true;
      }
      if (cur_point.i == n && cur_point.j == m) {
        isFind = true;
        break;
      }
      for (int dir = 0; dir < 4; dir++) {
        int next_i = cur_point.i + dir_i[dir];
        int next_j = cur_point.j + dir_j[dir];
        if (next_i < 1 || next_i > n || next_j < 1 || next_j > m) continue;
        if (cur_point.isWallPassed && visited_broken[next_i][next_j]) continue;
        if (cur_point.isWallPassed && matrix[next_i][next_j] == 1) continue;
        if (!cur_point.isWallPassed && visited[next_i][next_j]) continue;
        if (cur_point.isWallPassed) {
          visited_broken[next_i][next_j] = true;
        } else {
          visited[next_i][next_j] = true;
        }
        q.push({next_i, next_j, cur_point.isWallPassed});
      }
    }
    if (isFind) {
      break;
    }
  }
  if (!isFind) {
    turn = -1;
  }
  cout << turn << '\n';

  return 0;
}