#include <iostream>
using namespace std;

bool matrix[80] = {false, };

int getScore(string str){
    int ret = 0;
    //√ ±‚»≠
    for(int i = 0; i < 80; i++){
        matrix[i] = false;
    }
    //≈Ωªˆ
    for(int i = 0; i < str.length(); i++){
        if(!matrix[i]){
            if(str[i] == 'O'){
                int p = 1;
                for(int x = i; x < str.length(); x++){
                    if(str[x] == 'O'){
                        matrix[x] = true;
                        ret += p;
                        p++;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    return ret;
}

int main(){

    int n;
    cin >> n;
    string testCase[n+1];
    for(int i = 1; i <= n; i++){
        cin >> testCase[i];
    }
    for(int i = 1; i <= n; i++){
        cout << getScore(testCase[i]) << '\n';
    }

    return 0;
}
