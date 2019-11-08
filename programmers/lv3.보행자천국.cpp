#include <iostream>
#include <vector>

using namespace std;

int MOD = 20170805;

int findLeft(const int &_i, int _j, const vector<vector<int>> &city_map,
             const vector<vector<int>> &city_cnt) {
  /* while not 2 */
  while (--_j >= 0) {
    if (city_map[_i][_j] != 2) {
      return city_cnt[_i][_j];
    }
  }
  return 0;
}

int findTop(int _i, const int &_j, const vector<vector<int>> &city_map,
            const vector<vector<int>> &city_cnt) {
  /* while not 2 */
  while (--_i >= 0) {
    if (city_map[_i][_j] != 2) {
      return city_cnt[_i][_j];
    }
  }
  return 0;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
  int answer = 0;
  vector<vector<int>> city_cnt(m, vector<int>(n, 0));

  /* print */
  for (vector<int> v : city_map) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << '\n';
  }
  cout << "-----------------" << '\n';

  city_cnt[0][0] = 1;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0) continue;
      if (city_map[i][j] == 1) continue;
      city_cnt[i][j] = (findLeft(i, j, city_map, city_cnt) +
                       findTop(i, j, city_map, city_cnt)) % MOD;
    }
  }

  /* print */
  for (vector<int> v : city_cnt) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << '\n';
  }
  cout << '\n';

  answer = city_cnt[m - 1][n - 1];

  return answer;
}

int main() {
  cout << solution(3, 3, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}) << '\n';
  cout << solution(3, 6,
                   {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}})
       << '\n';

  return 0;
}