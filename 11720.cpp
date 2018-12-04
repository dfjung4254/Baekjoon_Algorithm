#include <iostream>
using namespace std;

int main(){

    int size;
    cin >> size;
    int sum = 0;
    string input;
    cin >> input;
    for(int i = 0; i < size; i++){
        sum += input[i] - '0';
    }
    cout << sum << endl;

    return 0;
}
