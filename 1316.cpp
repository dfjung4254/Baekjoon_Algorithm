#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int n;
bool matrix[26];

bool check(string input){
    memset(matrix, false, sizeof(matrix));
    int before = -1;
    for(int i = 0; i < input.size(); i++){
        int tpIdx = (int)input.at(i) - 97;
        if(!matrix[tpIdx] || before == tpIdx){
            //연속 인정.
            matrix[tpIdx] = true;
            before = tpIdx;
        }else{
            //불연속 그룹단어아님
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int ret = 0;
    while(n--){
        string input;
        cin >> input;
        if(check(input)){
            ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}