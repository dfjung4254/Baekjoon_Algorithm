#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ret = 100000001;

int main(){

  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int lp = 0;
  int rp = n-1;
  while(lp < rp){

    int sum = arr[lp] + arr[rp];
    if(abs(sum) < abs(ret)){
      ret = sum;
    }
    if(sum > 0){
      rp--;
    }else{
      lp++;
    }

  }
  cout << ret << endl;


  return 0;
}
