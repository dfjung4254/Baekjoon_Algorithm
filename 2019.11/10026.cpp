#include <iostream>
#include <queue>

using namespace std;

char matrix[101][101];
int visited[101][101];

int startBfs(int i, int j, int num){

  visited[i][j] = num;
  char standard = matrix[i][j];
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  } 

  /* case 1 */
  int case1 = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(visited[i][j] == 0){
        startBfs(i, j, ++case1);
      }
    }
  }

  return 0;
}
