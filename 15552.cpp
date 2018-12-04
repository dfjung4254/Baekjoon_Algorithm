#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int input;
    cin >> input;
    int ret[input];
    for(int i = 0; i < input; i++){
        int a, b;
        cin >> a >> b;
        ret[i] = a+b;
    }
    for(int i = 0; i < input; i++){
        cout << ret[i] << '\n';
    }

    return 0;
}
