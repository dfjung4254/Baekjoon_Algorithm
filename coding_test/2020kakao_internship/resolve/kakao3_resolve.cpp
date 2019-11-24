#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
set<int> check;

bool match(const string &cur_user_id, const string &cur_banned_id) {
  int usize = cur_user_id.size();
  int bsize = cur_banned_id.size();
  if (usize != bsize) {
    return false;
  }

  for (int i = 0; i < bsize; i++) {
    if (!(cur_user_id[i] == cur_banned_id[i] || cur_banned_id[i] == '*')) {
      return false;
    }
  }
  return true;
}

int vec2BitMask(const vector<bool> &v) {
  int size = v.size();
  int offset = 0;
  int ret = 0;
  for (bool bo : v) {
    if (bo) {
      ret += 1 << offset;
    }
    offset++;
  }
  return ret;
}

void bruteforce(int ban_idx, vector<string> &v, const vector<string> &user_id,
                const vector<string> &banned_id, int ban_size,
                vector<bool> &visited) {
  if (ban_idx >= ban_size) {
    /* finished */
    int bit_mask = vec2BitMask(visited);
    // cout << bit_mask << '\n';
    if (check.find(bit_mask) == check.end()) {
      for (const string &str : v) {
        cout << str << " ";
      }
      cout << '\n';
      check.insert(bit_mask);
    }

    return;
  }

  string cur_banned_id = banned_id[ban_idx];

  int idx = 0;
  for (const string &cur_user_id : user_id) {
    if (match(cur_user_id, cur_banned_id) && !visited[idx]) {
      v.push_back(cur_user_id);
      visited[idx] = true;
      bruteforce(ban_idx + 1, v, user_id, banned_id, ban_size, visited);
      v.pop_back();
      visited[idx] = false;
    }
    idx++;
  }
}

int solution(vector<string> user_id, vector<string> banned_id) {
  int answer = 0;

  int user_size = user_id.size();
  int banned_size = banned_id.size();

  vector<string> s;
  vector<bool> visited(user_size);
  bruteforce(0, s, user_id, banned_id, banned_size, visited);

  return answer;
}
int main() {
  cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},
                   {"fr*d*", "abc1**"})
       << '\n';
  // cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},
  //                  {"*rodo", "*rodo", "******"})
  //      << '\n';
  // cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"},
  //                  {"fr*d*", "*rodo", "******", "******"})
  //      << '\n';

  return 0;
}