#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

struct Node {
  int dist = INF;
  /* first : weight, second : index */
  vector<pair<int, int>> connected;
};
bool operator<(const Node &n1, const Node &n2) { return n1.dist > n2.dist; }

Node nodes[51];

void setBridge(Node &thisNode, const int &nextIdx, const int &weight) {
  thisNode.connected.push_back(make_pair(weight, nextIdx));
}

int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;

  /* node set */
  for (vector<int> thisRoad : road) {
    int n1 = thisRoad[0];
    int n2 = thisRoad[1];
    int weight = thisRoad[2];
    setBridge(nodes[n1], n2, weight);
    setBridge(nodes[n2], n1, weight);
  }

  nodes[1].dist = 0;
  priority_queue<Node> pq;
  pq.push(nodes[1]);
  while (!pq.empty()) {
    Node curNode = pq.top();
    pq.pop();
    for (pair<int, int> pa : curNode.connected) {
      int nextIdx = pa.second;
      int weight = pa.first;
      if (nodes[nextIdx].dist > curNode.dist + weight) {
        nodes[nextIdx].dist = curNode.dist + weight;
        pq.push(nodes[nextIdx]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    if (nodes[i].dist <= K) {
      answer++;
    }
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

  // cout
  //     << solution(
  //            5,
  //            {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}},
  //            3)
  //     << '\n';

  return 0;
}