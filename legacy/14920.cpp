#include <iostream>
using namespace std;

int n;

int main(){

  cin >> n;
  int count = 1;
  while(n != 1){
    if(n % 2 == 0){
      n = n / 2;
    }else{
      n = 3 * n + 1;
    }
    count++;
  }
  cout << count << endl;

  return 0;
}
