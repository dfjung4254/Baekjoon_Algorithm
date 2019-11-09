#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool check(long long &mid, set<long long> &delList, long long &target){

  /* exist */
  if(delList.find(mid) != delList.end()){
    return false;
  }

  return target <= mid;

}

vector<long long> solution(long long k, vector<long long> room_number) {
  vector<long long> answer;

  set<long long> delList;
  for (long long target : room_number) {

    /* binary search */
    long long ans = k;
    long long max = k;
    long long min = 1;
    long long mid;
    while(min < max){
      mid = (max + min) / 2;
      if(check(mid, delList, target)){
        max = mid;
      }else{
        min = mid + 1;
      }
    }

    delList.insert(mid);
    answer.push_back(mid);

  }

  return answer;
}

int main() {
  vector<long long> sol = solution(10, {1, 3, 4, 1, 3, 1});
  for (long long ll : sol) {
    cout << ll << " ";
  }
  cout << '\n';

  return 0;
}