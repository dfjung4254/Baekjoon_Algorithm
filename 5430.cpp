#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

vector<char> cmds;
deque<int> dq;
bool status;

void setCmd(string input){
    cmds.clear();
    for(int i = 0; i < input.size(); i++){
        cmds.push_back(input.at(i));
    }
}
void setDq(string input){
    dq.clear();
    string tmp = "";
    for(int i = 1; i < input.size(); i++){
        if(input.at(i) == ',' || input.at(i) == ']'){
            if(input.at(i) == ']' && i == 1){
                break;
            }
            dq.push_back(atoi(tmp.c_str()));
            tmp = "";
        }else{
            tmp += input.at(i);
        }
    }
}
void execCmd(){
    status = true;      //정방향
    bool isError = false;
    for(char cmd : cmds){
        switch(cmd){
            case 'R':
                status = (status == true) ? false:true;
                break;
            case 'D':
                if(dq.empty()){
                    isError = true;
                    break;
                }
                if(status){
                    //정방향
                    dq.pop_front();
                }else{
                    //역방향
                    dq.pop_back();
                }
                break;
            default:
                break;
        }
    }
    if(isError){
        cout << "error" << '\n';
    }else{
        // 결과 dq 출력. status 방향에따라서.
        if(status){
            cout << "[";
            for(auto it = dq.begin(); it != dq.end(); it++){
                if(it != dq.begin()){
                    cout << ",";
                }
                cout << *it;
            }
            cout << "]\n";
        }else{
            cout << "[";
            for(auto it = dq.rbegin(); it != dq.rend(); it++){
                if(it != dq.rbegin()){
                    cout << ",";
                }
                cout << *it;
            }
            cout << "]\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        string input;
        cin >> input;
        int n;
        cin >> n;
        string arr_input;
        cin >> arr_input;
        setCmd(input);
        setDq(arr_input);
        execCmd();
    }


    return 0;
}