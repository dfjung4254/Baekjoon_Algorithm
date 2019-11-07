#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(const vector<int> &v1, const vector<int> &v2) {
  if (v1[1] == v2[1]) {
    return v1[0] < v2[0];
  } else {
    return v1[1] < v2[1];
  }
}

int solution(vector<vector<int>> jobs) {
  int answer = 0;
  int size = jobs.size();

  sort(jobs.begin(), jobs.end(), compare);

  int t_start = 0;
  int t_finished = 0;
  while (!jobs.empty()) {
    /* 최저가 있는지 확인 해야 함 */
    /*

      1. 현재 시작점보다 작거나 같은 점이 있는가?
      2. 있다면 그거를 나오자마자 쓰면 되고
      3. 없다면 한단계 시작점을 올려서 검색. 500size 라 충분하다.

    */
    bool isFind = false;
    for (auto it = jobs.begin(); it != jobs.end(); it++) {
      vector<int> v = *it;
      if(v[0] <= t_start){
        /* 바로 꺼내 쓴다. */
        t_finished = t_start + v[1];
        answer += t_finished - v[0];
        t_start = t_finished;
        isFind = true;
        jobs.erase(it);
        break;
      }
    }
    /* 해당 t_start 이내에 jobs 가 없음 */
    if(!isFind){
      t_start++;
    }
  }

  answer /= size;

  return answer;
}

int main() {
  vector<vector<int>> v = {{0, 3}, {1, 9}, {2, 6}};

  cout << solution(v) << '\n';

  return 0;
}