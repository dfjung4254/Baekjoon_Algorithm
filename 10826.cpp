#include <iostream>
#include <string>
using namespace std;

int n;

//string 형태의 숫자는 좌우가 뒤집어진 형태로 존재한다.
//고로 마지막에 출력할때는 거꾸로 출력해주어야 한다.

string sum(string a, string b){
    string ret = "";
    if(b.size() > a.size()){
        string tp = a;
        a = b;
        b = tp;
    }
    int befStack = 0;
    for(int i = 0; i < a.size(); i++){
        int ca = a.at(i) - '0';
        int cb = 0;
        if(i < b.size()){
            cb = b.at(i) - '0';
        }
        int sum = ca + cb + befStack;
        befStack = sum / 10;
        int intRet = sum % 10;
        char chRet = intRet + '0';
        ret += chRet;
    }
    if(befStack == 1){
        ret += '1';
    }
    return ret;
}

string matrix[10001];

void fib(int n){
    string a = "0";
    string b = "1";
    string c = "";
    for(int i = 2; i <= n; i++){
        c = sum(a, b);
        a = b;
        b = c;
    }
    if(n == 0){
        cout << "0";
    }else if(n == 1){
        cout << "1";
    }else{
        for(int i = c.size()-1; i >= 0; i--){
            cout << c.at(i);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    matrix[0] = "0";
    matrix[1] = "1";
    fib(n);

    return 0;
}