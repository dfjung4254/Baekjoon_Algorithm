#include <iostream>
#include <string>

using namespace std;

string input;
int ret = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> input;
    for(int i = 0; i < input.size(); i++){
        int asc = (int)input.at(i); 
        int num = 0;
        if(asc <= 67)
            num = 2;
        else if(asc <= 70)
            num = 3;
        else if(asc <= 73)
            num = 4;
        else if(asc <= 76)
            num = 5;
        else if(asc <= 79)
            num = 6;
        else if(asc <= 83)
            num = 7;
        else if(asc <= 86)
            num = 8;
        else if(asc <= 90)
            num = 9;
        ret += num + 1;
    }
    cout << ret << endl;

    return 0;
}