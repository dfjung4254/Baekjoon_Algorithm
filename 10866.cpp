#include <iostream>
#include <string>
#include <deque>
using namespace std;

int n;
deque<int> dq;

void command(string cmd){
    if(cmd.compare("push_front") == 0){
        int input;
        cin >> input;
        dq.push_front(input);
    }else if(cmd.compare("push_back") == 0){
        int input;
        cin >> input;
        dq.push_back(input);
    }else if(cmd.compare("pop_front") == 0){
        if(dq.empty()){
            cout << -1 << '\n';
        }else{
            cout << dq.front() << '\n';
            dq.pop_front();
        }
    }else if(cmd.compare("pop_back") == 0){
        if(dq.empty()){
            cout << -1 << '\n';
        }else{
            cout << dq.back() << '\n';
            dq.pop_back();
        }
    }else if(cmd.compare("size") == 0){
        cout << dq.size() << '\n';
    }else if(cmd.compare("empty") == 0){
        if(dq.empty()){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }else if(cmd.compare("front") == 0){
        if(dq.empty()){
            cout << -1 << '\n';
        }else{
            cout << dq.front() << '\n';
        }
    }else if(cmd.compare("back")){
        if(dq.empty()){
            cout << -1 << '\n';
        }else{
            cout << dq.back() << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--){
        string cmd;
        cin >> cmd;
        command(cmd);
    }


    return 0;
}