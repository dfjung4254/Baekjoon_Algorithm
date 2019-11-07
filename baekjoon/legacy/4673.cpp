#include <iostream>
using namespace std;

bool matrix[10001] = {false, };

int getNextNumber(int number){

    int ret = 0;
    ret = number;
    string st = to_string(number);
    for(int i = 0; i < st.length(); i++){
        ret += st[i]-'0';
    }
    return ret;
}

int main(){
    for(int i = 1; i <= 10000; i++){
        if(matrix[i] == false){
            for(int num = getNextNumber(i); num <= 10000; num = getNextNumber(num)){
                matrix[num] = true;
            }
        }
    }
    for(int i = 1; i <= 10000; i++){
        if(matrix[i] == false){
            cout << i << '\n';
        }
    }
    return 0;
}
