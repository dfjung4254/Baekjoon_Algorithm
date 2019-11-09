#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
  vector<long long> answer;

  /* not good... for 10^12 */
  set<long long> s;
  for(long long i = 1; i <= k; i++){
    s.insert(i);
  }

  for(long long target : room_number){

    auto it = s.lower_bound(target);
    answer.push_back(*it);
    s.erase(it);

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