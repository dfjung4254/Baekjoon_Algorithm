#include <iostream>
using namespace std;

int main(){

    int a, b, c;
    cin >> a >> b >> c;
    int num = a*b*c;
    int ret[10] = {0, };
    string st = to_string(num);
    for(int i = 0; i < st.length(); i++){
        ret[st[i]-'0']++;
    }
    for(int i = 0; i < 10; i++){
        cout << ret[i] << endl;
    }
    return 0;
}
