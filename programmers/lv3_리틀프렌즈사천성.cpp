#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int TC_M[4] = {3, 2, 4, 2};
const int TC_N[4] = {3, 4, 4, 2};
const vector<string> TC_BOARD[4] = {{"DBA", "C*A", "CDB"},
                                    {"NRYN", "ARYA"},
                                    {".ZI.", "M.**", "MZU.", ".IU."},
                                    {"AB", "BA"}};
const string TC_ANSWER[4] = {"ABCD", "RYAN", "MUZI", "IMPOSSIBLE"};

int dir_i[4] = {0, 1, 0, -1};
int dir_j[4] = {1, 0, -1, 0};

bool isFindWithBFS(const char &target, const int &curi, const int &curj,
                   vector<string> &board, const int &m, const int &n) {
  /* 오 */
  for (int d = 1; d + curj < n; d++) {
    if (board[curi][curj + d] == '.') {
      for (int di = -1; di + curi >= 0; di--) {
        if (board[curi + di][curj + d] == target) {
          board[curi][curj] = '.';
          board[curi + di][curj + d] = '.';
          return true;
        } else if (board[curi + di][curj + d] != '.') {
          break;
        }
      }
      for (int di = 1; di + curi < m; di++) {
        if (board[curi + di][curj + d] == target) {
          board[curi][curj] = '.';
          board[curi + di][curj + d] = '.';
          return true;
        } else if (board[curi + di][curj + d] != '.') {
          break;
        }
      }
    } else if (board[curi][curj + d] == target) {
      board[curi][curj] = '.';
      board[curi][curj + d] = '.';
      return true;
    } else {
      break;
    }
  }

  /* 왼 */
  for (int d = -1; d + curj >= 0; d--) {
    if (board[curi][curj + d] == '.') {
      for (int di = -1; di + curi >= 0; di--) {
        if (board[curi + di][curj + d] == target) {
          board[curi][curj] = '.';
          board[curi + di][curj + d] = '.';
          return true;
        } else if (board[curi + di][curj + d] != '.') {
          break;
        }
      }
      for (int di = 1; di + curi < m; di++) {
        if (board[curi + di][curj + d] == target) {
          board[curi][curj] = '.';
          board[curi + di][curj + d] = '.';
          return true;
        } else if (board[curi + di][curj + d] != '.') {
          break;
        }
      }
    } else if (board[curi][curj + d] == target) {
      board[curi][curj] = '.';
      board[curi][curj + d] = '.';
      return true;
    } else {
      break;
    }
  }

  /* 위 */
  for (int d = -1; d + curi >= 0; d--) {
    if (board[curi + d][curj] == '.') {
      for (int dj = -1; dj + curj >= 0; dj--) {
        if (board[curi + d][curj + dj] == target) {
          board[curi][curj] = '.';
          board[curi + d][curj + dj] = '.';
          return true;
        } else if (board[curi + d][curj + dj] != '.') {
          break;
        }
      }
      for (int dj = 1; dj + curj < m; dj++) {
        if (board[curi + d][curj + dj] == target) {
          board[curi][curj] = '.';
          board[curi + d][curj + dj] = '.';
          return true;
        } else if (board[curi + d][curj + dj] != '.') {
          break;
        }
      }
    } else if (board[curi + d][curj] == target) {
      board[curi][curj] = '.';
      board[curi + d][curj] = '.';
      return true;
    } else {
      break;
    }
  }

  /* 아래 */
  for (int d = 1; d + curi < m; d++) {
    if (board[curi + d][curj] == '.') {
      for (int dj = -1; dj + curj >= 0; dj--) {
        if (board[curi + d][curj + dj] == target) {
          board[curi][curj] = '.';
          board[curi + d][curj + dj] = '.';
          return true;
        } else if (board[curi + d][curj + dj] != '.') {
          break;
        }
      }
      for (int dj = 1; dj + curj < m; dj++) {
        if (board[curi + d][curj + dj] == target) {
          board[curi][curj] = '.';
          board[curi + d][curj + dj] = '.';
          return true;
        } else if (board[curi + d][curj + dj] != '.') {
          break;
        }
      }
    } else if (board[curi + d][curj] == target) {
      board[curi][curj] = '.';
      board[curi + d][curj] = '.';
      return true;
    } else {
      break;
    }
  }

  return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
  string answer = "";

  set<char> alphabetList;
  for (string str : board) {
    for (char ch : str) {
      if (ch > 64 && ch < 91) {
        alphabetList.insert(ch);
      }
    }
  }

  while (!alphabetList.empty()) {
    bool operated = false;
    for (auto it = alphabetList.begin(); it != alphabetList.end();) {
      /* 연결되는 것을 찾으면 제거하고 빠져나온다 */
      char currentChar = *it;
      for (int i = 0; i < m; i++) {
        bool check = false;
        for (int j = 0; j < n; j++) {
          if (board[i][j] == currentChar) {
            check = true;
            if (isFindWithBFS(currentChar, i, j, board, m, n)) {
              answer += *it;
              alphabetList.erase(it);
              operated = true;
            } else {
              it++;
            }
            break;
          }
        }
        if (check) {
          break;
        }
      }
      if (operated) {
        break;
      }
    }
    if(!operated){
      answer = "IMPOSSIBLE";
      break;
    }
  }

  return answer;
}

int main() {
  /* test case */
  for (int i = 0; i < 4; i++) {
    cout << solution(TC_M[i], TC_N[i], TC_BOARD[i]) << '\n';
    // if (TC_ANSWER[i].compare(solution(TC_M[i], TC_N[i], TC_BOARD[i])) == 0) {
    //   cout << "clear" << '\n';
    // } else {
    //   cout << "failed" << '\n';
    // }
  }

  return 0;
}