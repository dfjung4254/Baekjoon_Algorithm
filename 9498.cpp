#include <iostream>
using namespace std;

int main(){

    int input;
    cin >> input;
    int target = input / 10;
    switch(target){
        case 10:
        cout << "A";
        break;
        case 9:
        cout << "A";
        break;
        case 8:
        cout << "B";
        break;
        case 7:
        cout << "C";
        break;
        case 6:
        cout << "D";
        break;
        default:
        cout << "F";
    }
    cout << endl;

    return 0;
}
