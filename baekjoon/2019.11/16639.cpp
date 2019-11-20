#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;
int n;
string input;

map<char, int> priority;

string getPostfix(string infix){

  stack<char> st;
  string result = "";

  for(char ch : infix){
    
  }

  return result;

}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  cin >> input;

  /* set map */
  priority.insert(make_pair('*', 3));
  priority.insert(make_pair('+', 2));
  priority.insert(make_pair('-', 2));
  priority.insert(make_pair('(', 1));

  string postfix = getPostfix(input);

  return 0;
}