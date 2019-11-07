#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> patterns[3] = {
  {1,2,3,4,5},
  {2,1,2,3,2,4,2,5},
  {3,3,1,1,2,2,4,4,5,5}
};

vector<int> solution(vector<int> answers) {
  vector<int> answer;
  int size = answers.size();
  vector<pair<int, int>> tp;

  for(int pt = 0; pt < 3; pt++){

    int correctNums = 0;
    vector<int> thisPattern = patterns[pt];
    int ptSize = thisPattern.size();

    for(int i = 0; i < size; i++){
      if(answers[i] == thisPattern[i % ptSize]){
        correctNums++;
      }
    }

    if(tp.empty() || tp.at(0).second == correctNums){
      tp.push_back(make_pair(pt+1, correctNums));
    }else if(tp.at(0).second < correctNums){
      tp.clear();
      tp.push_back(make_pair(pt+1, correctNums));
    }

  }  

  for(pair<int, int> pa : tp){
    answer.push_back(pa.first);
  }

  return answer;
}

int main() {
  vector<int> v = {1, 3, 2, 4, 2};
  vector<int> ans = solution(v);

  for (int num : ans) {
    cout << num << " ";
  }
  cout << '\n';

  return 0;
}