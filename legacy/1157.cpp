#include <iostream>
using namespace std;

int matrix[26] = {0, };
int maxCount = 0;
int maxIndex = 0;
bool joongbok = false;

int main(){

    string input;
    cin >> input;
    for(int i = 0; i < input.length(); i++){
        if((int)input[i] - 65 < 30){
            //대문자
            matrix[(int)input[i]-65]++;
        }else{
            //소문자
            matrix[(int)input[i]-97]++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(matrix[i] > maxCount){
            maxCount = matrix[i];
            maxIndex = i;
            joongbok = false;
        }else if(matrix[i] == maxCount){
            joongbok = true;
        }
    }
    if(joongbok){
        cout << "?" << endl;
    }else{
        cout << (char)(maxIndex+65) << endl;
    }

    return 0;
}
