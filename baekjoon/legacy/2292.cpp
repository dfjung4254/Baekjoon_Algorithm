#include <iostream>
using namespace std;

int input;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> input;
    int sCount = 0;
    int maxLine = 1;
    while(true){
        maxLine += 6 * sCount;
        if(input <= maxLine){
            break;
        }
        sCount++;
    }  
    cout << sCount+1 << endl;

    return 0;
}