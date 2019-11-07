#include <iostream>
using namespace std;

int main(){

    string input;
    getline(cin, input);

    for(int i = 0; i < input.size(); i++){

        if(i % 10 == 0 && i != 0){
            cout << '\n';
        }
        cout << input[i];

    }

    return 0;
}
