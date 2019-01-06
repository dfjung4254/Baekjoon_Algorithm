#include <iostream>
#include <string>
using namespace std;

string input;
const string enums[] = {
    "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
};
int ret = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> input;
    for(int i = 0; i < 8; i++){
        while(true){
            int loc = input.find(enums[i]);
            if(loc == string::npos)
                break;
            ret++;
            if(i != 2){
                input.at(loc) = '*';
                input.at(loc+1) = '*';
            }else{
                input.at(loc) = '*';
                input.at(loc+1) = '*';
                input.at(loc+2) = '*';
            }
        }
    }
    for(int i = 0; i < input.size(); i++){
        if(input.at(i) != '*'){
            ret++;
        }
    }
    cout << ret << '\n';

    return 0;
}