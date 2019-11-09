#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;

bool pushDoll(const int &nDoll){

  bool ret = true;
  if(v.empty() || v.back() != nDoll){
    /* push */
    v.push_back(nDoll);
    ret = false;
  }else{
    /* pop */
    v.pop_back();
  }

  return ret;
}

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  int size = board.size();

  for(int num : moves){
    int cur_j = num - 1;
    /* find top */
    for(int i = 0; i < size; i++){
      if(board[i][cur_j] != 0){
        if(pushDoll(board[i][cur_j])){
          answer++;
        }
        board[i][cur_j] = 0;
        break;
      }
    }

  }

  return answer * 2;
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