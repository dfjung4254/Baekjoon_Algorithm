#include <iostream>
#include <string>
using namespace std;

int n, r;
string memo[101][101];

string sum(string a, string b){
    string ret = "";
    if(a.size() < b.size()){
        string tp = a;
        a = b;
        b = tp;
    }
    int overflow = 0;
    for(int i = 0; i < a.size(); i++){
        int cha = a.at(i) - '0';
        int chb = 0;
        if(i < b.size()){
            chb = b.at(i) - '0';
        }
        int intret = (cha + chb + overflow) % 10;
        overflow = (cha + chb + overflow) / 10;
        ret += intret + '0';
    }
    if(overflow == 1){
        ret += "1";
    }
    return ret;
}

void comb(int n, int r){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || i == j){
                memo[i][j] = "1";
            }else{
                memo[i][j] = sum(memo[i-1][j], memo[i-1][j-1]);
            }
        }   
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r;
    comb(n, r);
    for(int k = memo[n][r].size()-1; k >= 0; k--){
        cout << memo[n][r].at(k);
    }

    return 0;
}