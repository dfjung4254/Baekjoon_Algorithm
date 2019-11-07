#include <iostream>
#include <queue>

using namespace std;

char matrix[101][101];
int visited[101][101];
const int dir_i[4] = {0, 1, 0, -1};
const int dir_j[4] = {1, 0, -1, 0};
int n;

void startBfs(const int &i, const int &j, const int &num,
              const bool &isDisabled) {
  char standard = matrix[i][j];
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  visited[i][j] = num;
  while (!q.empty()) {
    pair<int, int> current = q.front();
    q.pop();

    for (int direction = 0; direction < 4; direction++) {
      int next_i = current.first + dir_i[direction];
      int next_j = current.second + dir_j[direction];
      if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n ||
          visited[next_i][next_j] != 0) {
        continue;
      }

      if (isDisabled &&
          ((standard == 'B' && matrix[next_i][next_j] == standard) ||
           (standard != 'B' && matrix[next_i][next_j] != 'B'))) {
        visited[next_i][next_j] = num;
        q.push(make_pair(next_i, next_j));
      } else if (matrix[next_i][next_j] == standard) {
        visited[next_i][next_j] = num;
        q.push(make_pair(next_i, next_j));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  /* case 1 */
  int case1 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j] == 0) {
        startBfs(i, j, ++case1, false);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[i][j] = 0;
    }
  }

  /* case 2 */
  int case2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j] == 0) {
        startBfs(i, j, ++case2, true);
      }
    }
  }

  cout << case1 << " " << case2 << '\n';

  return 0;
}
