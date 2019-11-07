#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(const long long &num, const vector<int> &times,
           const int &n) {
  int target = 0;
  for (int i : times) {
    target += num / i;
  }
  return target < n;
}

long long solution(int n, vector<int> times) {

  long long max = (long long)times.back() * n;
  long long answer = max;
  long long min = 0;
  long long mid;

  while (min <= max) {
    mid = (max + min) / 2;
    if(check(mid, times, n)){
      min = mid + 1;
    }else{
      if(answer > mid){
        answer = mid;
      }
      max = mid - 1;
    }
  }

  return answer;
}

int main() {
  cout << solution(6, {7, 10}) << '\n';

  return 0;
}