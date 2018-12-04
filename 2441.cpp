#include <iostream>
using namespace std;

int main(){

    int input;
    cin >> input;
    for(int i = 1; i <= input; i++){
        for(int j = 1; j <= input; j++){
            if(i <= j){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
