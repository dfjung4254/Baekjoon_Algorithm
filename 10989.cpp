#include <iostream>
using namespace std;

short index[10001];

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        index[input]++;
    }
    for(int i = 1; i < 10001; i++){
        for(int j = 0; j < index[i]; j++){
            cout << i << '\n';
        }
    }

    return 0;
}
