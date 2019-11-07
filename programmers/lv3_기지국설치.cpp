#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w) {
  int answer = 0;
  int wavSize = 2 * w + 1;
  stations.push_back(n + 1 + w);

  int min, max = 0;
  for (int mid : stations) {
    int beforeMin = max;
    min = mid - w;
    max = mid + w;

    int gap = min - beforeMin - 1;
    if (gap > 0) {
      answer += (gap % wavSize == 0) ? gap / wavSize : gap / wavSize + 1;
    }
  }

  return answer;
}

int main() {
  cout << solution(11, {4, 11}, 1) << '\n';

  return 0;
}