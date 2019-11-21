#include <iostream>
#include <vector>
#include <string>

using namespace std;

void last_tokenize(const vector<string> &tokened, vector<vector<int>> tokened_result){

  string str_num = "";
  for(const string &str : tokened){
    vector<int> v;
    for(char ch : str){
      if(ch == ','){
        cout << "input : " << str_num << '\n';
        v.push_back(stoi(str_num));
        str_num = "";
      }else{
        str_num += ch;
      }
      // v.push_back(stoi(str_num));
    }
    tokened_result.push_back(v);
  }
  
  for(const vector<int> &v : tokened_result){
    for(int n : v){
      cout << n << " ";
    }
    cout << '\n';
  }

}

void tokenize(string &s, vector<string> &tokened_result) {
  int size = s.size() - 1;
  string input = "";
  bool isWiring = false;

  /* 앞, 뒤 제외 */
  for (int idx = 1; idx < size; idx++) {
    if (s[idx] == ',' && !isWiring) {
      tokened_result.push_back(input);
      input = "";
    } else if (s[idx] != '{' && s[idx] != '}') {
      input += s[idx];
    } else if (s[idx] == '{') {
      isWiring = true;
    } else {
      isWiring = false;
    }
  }
  tokened_result.push_back(input);
}

vector<int> solution(string s) {
  vector<int> ans;

  vector<string> tokened;
  tokenize(s, tokened);
  vector<vector<int>> last_tokenized;
  last_tokenize(tokened, last_tokenized);


  return ans;
}

int main() {
  vector<int> ans = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
  // vector<int> ans = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
  // vector<int> ans = solution("{{20,111},{111}}");
  // vector<int> ans = solution("{{123}}");
  // vector<int> ans = solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
  // for (int num : ans) {
  //   cout << num << " ";
  // }
  // cout << '\n';

  return 0;
}