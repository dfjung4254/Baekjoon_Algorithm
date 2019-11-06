#include <iostream>
using namespace std;

int main(){

    int testCase;
    cin >> testCase;
    pair<int, string> myCase[testCase];
    for(int i = 0; i < testCase; i++){
        cin >> myCase[i].first >> myCase[i].second;
    }

    for(int i = 0; i < testCase; i++){
        for(int j = 0; j < myCase[i].second.length(); j++){
            for(int k = 0; k < myCase[i].first; k++){
                cout << myCase[i].second[j];
            }
        }
        cout << '\n';
    }

    return 0;
}
