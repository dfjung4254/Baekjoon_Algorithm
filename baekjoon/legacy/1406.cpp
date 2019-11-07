#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> stLeft;
vector<char> stRight;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string input;
    cin >> input;
    for(int i = 0; i < input.size(); i++){
        stLeft.push_back(input.at(i));
    }
    int n;
    cin >> n;
    while(n--){
        char cmd;
        cin >> cmd;
        char tp;
        switch(cmd){
            case'L':
                if(!stLeft.empty()){
                    tp = stLeft.back();
                    stLeft.pop_back();
                    stRight.push_back(tp);
                }
                break;
            case'D':
                if(!stRight.empty()){
                    tp = stRight.back();
                    stRight.pop_back();
                    stLeft.push_back(tp);
                }
                break;
            case'B':
                if(!stLeft.empty()){
                    stLeft.pop_back();
                }
                break;
            case'P':
                cin >> tp;
                stLeft.push_back(tp);
                break;
            default:
                break;
        }
    }
    for(char ch : stLeft){
        cout << ch;
    }
    while(!stRight.empty()){
        cout << stRight.back();
        stRight.pop_back();
    }

    return 0;
}