#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int input;
    cin >> input;
    int num[input];
    for(int i = 0; i < input; i++){
        cin >> num[i];
    }
    sort(num, num+input);
    for(int i = 0; i < input; i++){
        cout << num[i] << '\n';
    }

    return 0;
}
