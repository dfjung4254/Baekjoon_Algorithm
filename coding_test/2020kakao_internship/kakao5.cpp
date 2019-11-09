#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(vector<int> &stones, int &k, int &mid){

  int size = stones.size();

  int cnt = 0;
  for(int i = 0; i < size; i++){
    if(stones[i] - mid < 0){
      cnt++;
    }else{
      cnt = 0;
    }
    if(cnt >= k){
      return false;
    }
  }
  return true;
}

int solution(vector<int> stones, int k) {
  int answer = 0;

  int max = 200000001;
  int min = 0;
  int mid;
  while(min <= max){
    mid = (max + min) / 2;
    if(check(stones, k, mid)){
      if(answer < mid){
        answer = mid;
      }
      min = mid + 1;
    }else{
      max = mid - 1;
    }
  }

  return answer;
}

int main() {
  cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3);

  return 0;
}