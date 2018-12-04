#include <iostream>
using namespace std;

int alpha[26];

int main(){
    for(int i = 0; i < 26; i++){
        alpha[i] = -1;
    }
    string input;
    cin >> input;
    for(int i = 0; i < input.length(); i++){
        if(alpha[(int)input[i]-97] == -1){
            alpha[(int)input[i]-97] = i;
        }
    }
    for(int i = 0; i < 26; i++){
        cout << alpha[i] << " ";
    }
    cout << endl;

    return 0;
}
