#include <iostream>
using namespace std;

int matrix[1001][1001];
bool visited[1001][1001] = {false, };

int n, m;
int curn, curm;
int tarn, tarm;
int ret = -1;

void dfs(int curx, int cury, int prex, int prey, int use, int count){

  if(curx == tarn && cury == tarm){
      if(ret == -1 || ret > count){
          ret = count;
      }
      return;
  }
  visited[curx][cury] = true;
  cout << curx <<"/" << cury << " :¹æ¹®" << endl;
  //left
  if(cury != 1 && visited[curx][cury-1] == false){
      if(matrix[curx][cury-1] == 0){
          dfs(curx, cury-1, curx, cury, use, count+1);
      }else{
          if(use == 0){
              dfs(curx, cury-1, curx, cury, use+1, count+1);
          }
      }
  }
  visited[curx][cury-1] = false;
  //up
  if(curx != 1 && visited[curx-1][cury] == false){
      if(matrix[curx-1][cury] == 0){
          dfs(curx-1, cury, curx, cury, use, count+1);
      }else{
          if(use == 0){
              dfs(curx-1, cury, curx, cury, use+1, count+1);
          }
      }
  }
  visited[curx-1][cury] = false;
  //right
  if(cury != m && visited[curx][cury+1] == false){
      if(matrix[curx][cury+1] == 0){
          dfs(curx, cury+1, curx, cury, use, count+1);
      }else{
          if(use == 0){
              dfs(curx, cury+1, curx, cury, use+1, count+1);
          }else{

          }
      }
  }
  visited[curx][cury+1] = false;
  //down
  if(curx != n && visited[curx+1][cury] == false){
      if(matrix[curx+1][cury] == 0){
          dfs(curx+1, cury, curx, cury, use, count+1);
      }else{
          if(use == 0){
              dfs(curx+1, cury, curx, cury, use+1, count+1);
          }
      }
  }
  visited[curx+1][cury] = false;

}

int main(){

  cin >> n >> m;
  cin >> curn >> curm;
  cin >> tarn >> tarm;
  for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
          cin >> matrix[i][j];
      }
  }
  dfs(curn, curm, 0, 0, 0, 0);
  cout << ret << endl;

  return 0;
}
