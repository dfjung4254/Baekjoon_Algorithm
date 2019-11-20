#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;
int n;
string input;

map<char, int> priority;

char calculate(int num1, int num2, char sign) {
  int num = 0;
  switch (sign) {
    case '*':
      num = num1 * num2;
      break;
    case '+':
      num = num1 + num2;
      break;
    case '-':
      num = num1 - num2;
      break;
    case '/':
      num = num1 / num2;
    default:
      break;
  }
  return (num + '0');
}

int getAnswer(string postfix) {
  stack<char> st;
  int result = 0;

  for (char ch : postfix) {
    if (ch >= '0' && ch <= '9') {
      st.push(ch);
    } else {
      int num2 = st.top() - '0';
      st.pop();
      int num1 = st.top() - '0';
      st.pop();
      st.push(calculate(num1, num2, ch));
    }
  }
  result = st.top() - '0';

  return result;
}

string getPostfix(string infix) {
  stack<char> st;
  string result = "";

  for (char ch : infix) {
    if (ch >= '0' && ch <= '9') {
      /* number */
      result += ch;
    } else {
      /* sign */
      while (!st.empty() &&
             priority.find(st.top())->second >= priority.find(ch)->second) {
        result += st.top();
        st.pop();
      }
      st.push(ch);
    }
  }
  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> input;

  /* set map */
  priority.insert(make_pair('*', 3));
  priority.insert(make_pair('/', 3));
  priority.insert(make_pair('+', 2));
  priority.insert(make_pair('-', 2));
  priority.insert(make_pair('(', 1));

  string postfix = getPostfix(input);

  cout << postfix << '\n';

  // cout << getAnswer(postfix) << '\n';

  return 0;
}