#include <iostream>
using namespace std;

int main(){

    int input;
    int ret = 0;
    cin >> input;
    for(int i = 1; i <= input; i++){
        ret+=i;
    }
    cout << ret << endl;

    return 0;
}
