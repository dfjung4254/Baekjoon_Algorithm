#include <iostream>

using namespace std;

int matrix[200001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, v;
  cin >> n >> m >> v;
  for(int i = 0; i < n; i++){
    cin >> matrix[i];
  }

  int cycle = n - v + 1;
  int limit = n - cycle;

  for(int i = 0; i < m; i++){
    int target;
    cin >> target;

    if(target < n){
      cout << matrix[target] << '\n';
    }else{
      int tp = target % cycle;
      if(tp < limit){
        int ttp = (tp + limit) % cycle;
        cout << matrix[ttp + cycle] << '\n';
      }else{
        cout << matrix[tp] << '\n';
      }
    }

  }

  return 0;
}