#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
vector<int> v;
vector<int> tp;

int main(){

    cin >> input;
    bool flag = true;
    for(int i = 0; i < input.length(); i++){

        char cur = input[i];
        if(cur == '('){
            v.push_back(-1);
        }else if(cur == '['){
            v.push_back(-2);
        }else if(cur == ')'){
            while(true){
                if(v.size() == 0){
                    flag = false;
                    break;
                }
                int tmp = v.back();
                if(tmp == -1){
                    int ret = 0;
                    for(auto it = tp.begin(); it != tp.end(); it++){
                        ret += (*it);
                    }
                    ret = (ret == 0) ? 2:2*ret;
                    v.pop_back();
                    v.push_back(ret);
                    tp.clear();
                    break;
                }else if(tmp == -2){
                    flag = false;
                    break;
                }else{
                    v.pop_back();
                    tp.push_back(tmp);
                }
            }
        }else if(cur == ']'){
            while(true){
                if(v.size() == 0){
                    flag = false;
                    break;
                }
                int tmp = v.back();
                if(tmp == -2){
                    int ret = 0;
                    for(auto it = tp.begin(); it != tp.end(); it++){
                        ret += (*it);
                    }
                    ret = (ret == 0) ? 3:3*ret;
                    v.pop_back();
                    v.push_back(ret);
                    tp.clear();
                    break;
                }else if(tmp == -1){
                    flag = false;
                    break;
                }else{
                    v.pop_back();
                    tp.push_back(tmp);
                }
            }
        }
        if(!flag){break;}
        // cout << "현재 스택 : ";
        // for(auto it = v.begin(); it != v.end(); it++){
        //     cout << *it << " ";
        // }
        // cout << endl;
    }
    int ret = 0;
    for(auto it = v.begin(); it != v.end(); it++){
        if(*it < 0){
            flag = false;
            break;
        }
        ret += *it;
    }
    if(!flag){
        ret = 0;
    }
    cout << ret << endl;
    return 0;
}
