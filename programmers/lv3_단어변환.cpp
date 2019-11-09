#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int visited[51] = {
    0,
};

bool wordFind(const string &curStr, const string &nextStr, const int &wSize) {
  int overlapCnt = 0;

  for (int i = 0; i < wSize; i++) {
    if (curStr[i] == nextStr[i]) {
      overlapCnt++;
    }
  }

  return overlapCnt == wSize - 1;
}

int solution(string begin, string target, vector<string> words) {
  int answer = 0;
  int size = words.size();
  int wSize = begin.size();

  queue<pair<string, int>> q;
  q.push(make_pair(begin, 0));
  while (!q.empty()) {
    string curStr = q.front().first;
    int curIdx = q.front().second;
    q.pop();
    for (int i = 0; i < size; i++) {
      if (visited[i] != 0) continue;
      if (wordFind(curStr, words[i], wSize)) {
        visited[i] = curIdx + 1;
        if(words[i].compare(target) == 0){
          return visited[i];
        }
        q.push(make_pair(words[i], visited[i]));
      }
    }
  }

  return 0;
}

int main() {
  // cout << solution("hit", "cog",
  //                  {"hot", "dot", "dog",
  //                   "lot"
  //                   "log",
  //                   "cog"})
  //      << '\n';
  cout << solution("hit", "cog",
                   {"hot", "dot", "dog",
                    "lot"
                    "log"})
       << '\n';
  return 0;
}