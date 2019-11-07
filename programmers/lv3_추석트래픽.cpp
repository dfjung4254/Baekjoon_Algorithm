#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct LogTime {
  int start;
  int end;
};

LogTime parse(string log) {
  int cnt = 0;
  int size = log.size();
  string block[3] = {
      "",
  };
  for (int i = 0; i < size; i++) {
    if (log[i] == ' ') {
      if (cnt == 0) {
        cnt++;
      } else if (cnt == 1) {
        cnt++;
      }
    } else {
      block[cnt] += log[i];
    }
  }

  LogTime ret = {0, 0};
  string tmp = "";
  tmp += block[1][0];
  tmp += block[1][1];
  ret.start = stoi(tmp) * 1000 * 60 * 60;
  tmp = "";
  tmp += block[1][3];
  tmp += block[1][4];
  ret.start += stoi(tmp) * 1000 * 60;
  tmp = "";
  tmp += block[1][6];
  tmp += block[1][7];
  ret.start += stoi(tmp) * 1000;
  tmp = "";
  tmp += block[1][9];
  tmp += block[1][10];
  tmp += block[1][11];
  ret.start += stoi(tmp);

  tmp = "";
  tmp += block[2][0];
  int mSecond = stoi(tmp) * 1000;
  int idx = 1;
  tmp = "";
  while (block[2][idx] != 's') {
    if (block[2][idx] != '.') {
      tmp += block[2][idx];
    }
    idx++;
  }

  while(tmp.size() != 3){
    tmp += "0";
  }
  mSecond += stoi(tmp);

  ret.end = ret.start - mSecond + 1;

  return ret;
}

int solution(vector<string> lines) {
  int answer = 0;
  vector<LogTime> logTimes;

  for (string str : lines) {
    logTimes.push_back(parse(str));
  }

  int size = logTimes.size();
  for (int i = 0; i < size; i++) {
    int cnt = 1;
    for (int j = i + 1; j < size; j++) {
      if (logTimes[j].end <= logTimes[i].start + 999) {
        cnt++;
      } else if (logTimes[j].start <= logTimes[i].start + 999) {
        cnt++;
      } else if (logTimes[j].start <= logTimes[i].end) {
        cnt++;
      }
    }
    if (answer < cnt) {
      answer = cnt;
    }
  }

  return answer;
}

int main() {
  vector<string> v1 = {"2016-09-15 01:00:04.001 2.0s",
                       "2016-09-15 01:00:07.000 2s"};

  vector<string> v2 = {"2016-09-15 01:00:04.002 2.0s",
                       "2016-09-15 01:00:07.000 2s"};

  vector<string> v3 = {
      "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s",
      "2016-09-15 20:59:58.299 0.8s",   "2016-09-15 20:59:58.688 1.041s",
      "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s",
      "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s",
      "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"};

  cout << solution(v1) << '\n';
  cout << solution(v2) << '\n';
  cout << solution(v3) << '\n';

  return 0;
}