#include <iostream>
using namespace std;

int main(){

    int size;
    cin >> size;
    string ret[size];
    for(int i = 0; i < size; i++){

        string input;
        cin >> input;
        int leftStack = 0;
        int rightStack = 0;
        for(int j = 0; j < input.size(); j++){
            if(input[j] == '('){
                leftStack++;
            }else{
                rightStack++;
            }
            if(rightStack > leftStack){
                ret[i] = "NO";
            }
        }
        if(leftStack == rightStack){
            if(ret[i] != "NO"){
                ret[i] = "YES";
            }
        }else{
            ret[i] = "NO";
        }
    }
    for(int i = 0; i < size; i++){
        cout << ret[i] << endl;
    }


    return 0;
}
