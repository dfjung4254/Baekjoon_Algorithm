#include <iostream>
#include <string>
using namespace std;

int main(){

    string input;
    for(int i = 0; i < 100; i++){
        getline(cin, input);
        if(input == "" || input.empty() || input == "\n"){
            break;
        }
        cout << input << endl;
    }

    return 0;
}
