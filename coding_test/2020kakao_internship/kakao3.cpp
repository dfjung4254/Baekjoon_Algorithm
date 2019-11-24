#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool match(const string &userId, const string &bannedId) {
  int usize = userId.size();
  int bsize = bannedId.size();
  if (usize != bsize) {
    return false;
  }

  for (int i = 0; i < bsize; i++) {
    if (!(userId[i] == bannedId[i] || bannedId[i] == '*')) {
      return false;
    }
  }
  return true;
}

vector<set<string>> ans;

void bruteForce(const int &userIdx, const int &banIdx, set<string> &v, const int &user_size,
                const int &ban_size, const vector<string> &user_id,
                const vector<string> &banned_id) {
  if (v.size() == ban_size) {

    for(const string &str : v){
      cout << str << " ";
    }
    cout << '\n';

    /* compare */
    bool haveSame = false;
    for(set<string> s : ans){
      bool isCorrespond = true;
      for(string str : s){
        if(v.find(str) == v.end()){
          isCorrespond = false;
          break;
        }
      }
      if(isCorrespond){
        haveSame = true;
      }
    }
    if(!haveSame){
      ans.push_back(v);
    }

    return;
  }

  if (userIdx >= user_size || banIdx >= ban_size) {
    return;
  }

  string curBanStr = banned_id[banIdx];
  string curUserStr = user_id[userIdx];

  if (match(curUserStr, curBanStr) && v.find(curUserStr) == v.end()) {
    v.insert(curUserStr);
    bruteForce(0, banIdx + 1, v, user_size, ban_size, user_id, banned_id);
    v.erase(curUserStr);
    bruteForce(userIdx + 1, banIdx, v, user_size, ban_size, user_id, banned_id);
  } else {
    bruteForce(userIdx + 1, banIdx, v, user_size, ban_size, user_id, banned_id);
  }
}

int solution(vector<string> user_id, vector<string> banned_id) {
  int answer = 0;

  int user_size = user_id.size();
  int ban_size = banned_id.size();

  set<string> s;
  bruteForce(0, 0, s, user_size, ban_size, user_id, banned_id);

  answer = ans.size();
  return answer;
}

int main() {
  // cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},
  //                  {"fr*d*", "abc1**"})
  //      << '\n';
  // cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},
  //                  {"*rodo", "*rodo", "******"})
  //      << '\n';
  cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},
                   {"fr*d*", "*rodo", "******", "******"})
       << '\n';

  return 0;
}