#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> v;
string ans = "";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    v.push_back(input);
  }

  int str_size = v[0].length();
  char saved_str = v[0][0];
  char plusChar = '?';

  for (int i = 0; i < str_size; i++) {
    saved_str = v[0][i];
    plusChar = saved_str;
    for (const string &str : v) {
      if (str[i] != saved_str) {
        plusChar = '?';
        break;
      }
    }
    ans += plusChar;
  }

  cout << ans << '\n';

  return 0;
}