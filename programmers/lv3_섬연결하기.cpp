#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int root[101];
int rootcnts[101];

int findRoot(const int &num){
  if(root[num] == num){
    return num;
  }else{
    return root[num] = findRoot(root[num]);
  }
}

int solution(int n, vector<vector<int>> costs) {
  int answer = 0;
  int bridgeSize = costs.size();

  /* initialize */
  for (int i = 0; i < n; i++) {
    root[i] = i;
    rootcnts[i] = 1;
  }

  sort(costs.begin(), costs.end(),
       [](const vector<int> &v1, const vector<int> &v2) -> bool {
         return v1[2] < v2[2];
       });

  /* 하나씩 놓아보면서 cycle 여부 검출 */
  for (vector<int> thisBridge : costs) {
    int root1 = findRoot(thisBridge[0]);
    int root2 = findRoot(thisBridge[1]);
    if (root1 != root2) {
      /* need connect */
      if(rootcnts[root1] > rootcnts[root2]){
        root[root2] = root1;
      }else{
        root[root1] = root2;
      }
      answer += thisBridge[2];
    }
  }

  return answer;
}

int main() {
  cout << solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}})
       << '\n';

  return 0;
}