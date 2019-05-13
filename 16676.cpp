#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string n;
int ans = 0;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int size = n.size();

    int num = stoi(n);
    string tp = "";
    for (int i = 0; i < size; i++){
        tp += "1";
    }
    int cpnum = stoi(tp) - 1;
    if(num > cpnum){
        ans = size;
    }else{
        ans = size - 1;
    }

    if(ans == 0){
        ans = 1;
    }

    cout << ans << '\n';
    return 0;
}