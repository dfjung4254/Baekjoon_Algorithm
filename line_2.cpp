#include <iostream>
#include <vector>
#include <string>
using namespace std;

string input;
vector<string> v_alphabet;
vector<int> v_number;

void parseNumber(int num){

    /*

        num이 0인 경우 back()이 1임을 확인하고(1이어야 한다)
        back()의 숫자를 10으로 바꾸어준다
        
        다른 경우에는 새로 push

    */

    if(num == 0 && v_number.back() == 1){
        v_number.back() = 10;
    }else{
        v_number.push_back(num);
    }

}

void parseAlphabet(char ch){

    /*

        들어온 문자가 대문자면 새로 push
        소문자면 기준 벡터의 back()에 ch를 더한다

    */

   if(ch <= 'Z'){
       /* 대문자인 경우 */
       v_alphabet.push_back("");
       v_alphabet.back() += ch;
   }else{
       /* 소문자인 경우 */
       v_alphabet.back() += ch;
   }

}

void parse(){

    /*

       1. 들어온 문자는 알파벳이냐 숫자냐

    */

    int str_size = input.size();
    for(int i = 0; i < str_size; i++){
        char _this = input[i];
        if(_this <= '9'){
            /* 숫자인 경우 */
            parseNumber(_this - '0');
        }else{
            /* 문자인 경우 */
            parseAlphabet(_this);
        }
    }

}

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> input;
    
    parse();

    int num_size = v_number.size();
    int ch_size = v_alphabet.size();
    if(num_size != ch_size){
        cout << "error" << '\n';
    }else{
        for(int i = 0; i < num_size; i++){
            cout << v_alphabet[i];
            if(v_number[i] != 1){
                cout << v_number[i];
            }
        }
    }

    return 0;
}