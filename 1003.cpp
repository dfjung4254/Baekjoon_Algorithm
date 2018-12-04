#include <iostream>
#include <utility>
using namespace std;

void findPair(int n, pair<int, int> &pair){

    pair.first = 1;
    pair.second = 0;

    for(int i = 0; i < n; i++){
        int tmpFirst = pair.first;
        int tmpSecond = pair.second;
        pair.first = tmpSecond;
        pair.second = tmpFirst+tmpSecond;
    }

}

int main(){

    int testCase;
    cin >> testCase;
    int input[testCase];
    pair<int, int> pair[testCase];
    for(int i = 0; i < testCase; i++){
        cin >> input[i];
        findPair(input[i], pair[i]);
    }
    for(int i = 0; i < testCase; i++){
        cout << pair[i].first << " " << pair[i].second << endl;
    }

    return 0;
}
