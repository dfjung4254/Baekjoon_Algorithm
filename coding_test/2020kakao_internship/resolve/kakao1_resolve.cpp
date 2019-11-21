#include <iostream>
#include <vector>

using namespace std;

/*

  카카오 1번
  간단한 구현(시뮬레이션) 문제.

*/

void checkAndPush(vector<int> &st, int num, int &count) {

  if (!st.empty() && st.back() == num) {
    count++;
    st.pop_back();
  } else {
    st.push_back(num);
  }
}

int pick(int t_idx, vector<vector<int>> &board, int size) {
  int picked_num = 0;

  for (int height = 0; height < size; height++) {
    if (board[height][t_idx] != 0) {
      picked_num = board[height][t_idx];
      board[height][t_idx] = 0;
      break;
    }
  }

  return picked_num;
}

int solution(vector<vector<int>> board, vector<int> moves) {
  int size = board.size();
  int count = 0;
  vector<int> st;

  for (int t_idx : moves) {
    /* pick num */
    int picked_num = pick(t_idx - 1, board, size);

    /* check and push */
    if (picked_num != 0) {
      checkAndPush(st, picked_num, count);
    }
  }

  return count * 2;
}

int main() {
  cout << solution({{0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 3},
                    {0, 2, 5, 0, 1},
                    {4, 2, 4, 4, 2},
                    {3, 5, 1, 3, 1}},
                   {1, 5, 3, 5, 1, 2, 1, 4})
       << '\n';

  return 0;
}