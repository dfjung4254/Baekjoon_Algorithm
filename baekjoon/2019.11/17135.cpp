#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define LINEBUFFER 20

using namespace std;

int n, m, d;
int matrix_origin[16 + LINEBUFFER][16];
int ans = -1;

pair<int, int> findTarget(int c_i, int c_j, int matrix[][16]) {
  int dist = -1;
  pair<int, int> ret = make_pair(-1, -1);


  for (int j = 0; j < m; j++) {
    for (int i = c_i - 1; i >= LINEBUFFER; i--) {
      if (matrix[i][j] == 1) {
        int tp_dist = abs(i - c_i) + abs(j - c_j);
        if (tp_dist > d) continue;
        if (dist == -1 || dist > tp_dist) {
          dist = tp_dist;
          ret = make_pair(i, j);
        }
      }
    }
  }

  return ret;
}

int simulation(vector<int> &v) {
  
  int matrix[16 + LINEBUFFER][16] = {0, };
  for(int i = LINEBUFFER; i < n + LINEBUFFER; i++){
    for(int j = 0; j < m; j++){
      matrix[i][j] = matrix_origin[i][j];
    }
  }

  int cnt = 0;
  queue<pair<int, int>> q;
  for (int castle_i = LINEBUFFER + n; castle_i > LINEBUFFER; castle_i--) {
    for (int castle_j : v) {
      pair<int, int> target = findTarget(castle_i, castle_j, matrix);
      if (target.first != -1) {
        q.push(target);
      }
    }
    while (!q.empty()) {
      pair<int, int> pa = q.front();
      q.pop();
      if (matrix[pa.first][pa.second] == 1) {
        matrix[pa.first][pa.second] = 0;
        cnt++;
      }
    }
  }

  return cnt;
}

void brute_case(int cur_idx, int cur_num, vector<int> &v) {
  if (cur_idx >= 3) {
    /* find case */
    int tp_ans = simulation(v);
    if (ans == -1 || ans < tp_ans) {
      ans = tp_ans;
    }
    return;
  }

  if (cur_num >= m) {
    return;
  }

  v[cur_idx] = cur_num;
  brute_case(cur_idx + 1, cur_num + 1, v);
  brute_case(cur_idx, cur_num + 1, v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> d;
  for (int i = LINEBUFFER; i < n + LINEBUFFER; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix_origin[i][j];
    }
  }

  vector<int> v(3);
  brute_case(0, 0, v);
  cout << ans << '\n';

  return 0;
}