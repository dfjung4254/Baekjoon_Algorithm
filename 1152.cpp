#include <iostream>
#include <string>
using namespace std;

int main(){

    string input;
    getline(cin, input, '\n');
    bool countOn = true;
    int count = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] != ' ' && countOn == true){
            countOn = false;
            count++;
        }
        if(input[i] == ' ' && countOn == false){
            countOn = true;
        }
    }
    cout << count << endl;

    return 0;
}
