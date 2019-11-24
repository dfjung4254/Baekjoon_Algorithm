#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool comp(const set<int> &v1, const set<int> &v2) {
  return v1.size() < v2.size();
}

vector<int> solution(string s) {
  vector<int> answer;

  s.erase(s.size() - 1);
  s.erase(0, 1);

  int idx = 0;
  int size = s.size();

  /* tokenizing */
  vector<set<int>> v;
  for (; idx < size; idx++) {
    if (s[idx] == '{') {
      idx++;
      set<int> tp;
      while (s[idx] != '}') {
        string buf = "";
        while (s[idx] != ',' && s[idx] != '}') {
          buf += s[idx];
          idx++;
        }
        if (s[idx] == '}') {
          tp.insert(stoi(buf));
          break;
        }

        if (buf.compare("") != 0) {
          tp.insert(stoi(buf));
        }
        idx++;
        if (s[idx] == '}') {
          break;
        }
      }
      v.push_back(tp);
    }
  }

  // sort(v.begin(), v.end(), comp);
  sort(v.begin(), v.end(), [](const set<int> &v1, const set<int> &v2)-> bool {
    return v1.size() < v2.size();
  });

  set<int> before;
  set<int>::iterator it;
  for(set<int> next : v){

    for(int num : next){
      it = before.find(num);
      if(it == before.end()){
        answer.push_back(num);
        before = next;
        break;
      }
    }

  }

  return answer;
}

int main() {
  // vector<int> ans = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
  // vector<int> ans = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
  // vector<int> ans = solution("{{20,111},{111}}");
  // vector<int> ans = solution("{{123}}");
  vector<int> ans = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
  for (int num : ans) {
    cout << num << " ";
  }
  cout << '\n';

  return 0;
}