#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(const vector<int> &budgets, const int &M, const int &m) {
  long long sum = 0;
  int size = budgets.size();
  int i = 0;
  for(; i < size; i++){
    if(budgets[i] > m){
      break;
    }else{
      sum += budgets[i];
    }
  }
  sum += (size - 1 - i) * m;

  return (M >= sum);
}

int solution(vector<int> budgets, int M) {
  int answer = 0;

  sort(budgets.begin(), budgets.end());

  /* binary search */
  int min = budgets[0];
  int max = budgets.back();
  int mid = 0;

  while (min < max) {
    mid = (max + min) / 2;
    cout << "Mid : " << mid << '\n';
    if(check(budgets, M, mid)){
      min = mid;
    }else{
      max = mid - 1;
    }
  }

  answer = (max + min) / 2;

  return answer;
}

int main() {
  vector<int> v = {120, 110, 140, 150};
  int m = 485;

  cout << solution(v, m) << '\n';

  return 0;
}