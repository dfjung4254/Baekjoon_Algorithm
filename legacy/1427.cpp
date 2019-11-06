#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string input;
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        int tp = input.at(i) - '0';
        v.push_back(tp);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i : v){
        cout << i;
    }
    cout << '\n';

    return 0;
}