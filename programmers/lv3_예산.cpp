#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(const int &expect, const int &M, const vector<int> &budgets) {
  long sum = 0;
  for (int num : budgets) {
    if (num > expect) {
      sum += expect;
    } else {
      sum += num;
    }
  }
  return sum <= M;
}

int solution(vector<int> budgets, int M) {
  int answer = 0;

  long min = 0;
  long max = 0;
  for (int i: budgets){
    if(max < i){
      max = i;
    }
  }
  long mid;
  while (min <= max) {
    mid = (min + max) / 2;
    if (check(mid, M, budgets)) {
      if (answer < mid) {
        answer = mid;
      }
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }

  return answer;
}

int main() {
  cout << solution({1,2,3,4,5,6,7,8,9,10}, 56) << '\n';
  return 0;
}