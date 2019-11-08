#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct Node {
  int dist;
  /* first : weight, second : index */
  vector<pair<int, int>> connected;
};
Node nodes[51];

void setBridge(Node &thisNode, const int &nextIdx, const int &weight){
  thisNode.connected.push_back(make_pair(weight, nextIdx));
}

int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;

  /* 중복제거, node set */
  for(vector<int> thisRoad : road){
    int n1 = thisRoad[0];
    int n2 = thisRoad[1];
    int weight = thisRoad[2];
    
    setBridge(nodes[n1], n2, weight);

  }

  return answer;
}

int main() {
  cout << solution(6,
                   {{1, 2, 1},
                    {1, 3, 2},
                    {2, 3, 2},
                    {3, 4, 3},
                    {3, 5, 2},
                    {3, 5, 3},
                    {5, 6, 1}},
                   4)
       << '\n';

  return 0;
}