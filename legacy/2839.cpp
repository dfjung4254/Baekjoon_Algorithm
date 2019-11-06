#include <iostream>
using namespace std;

int main(){

    int target;
    int fiveCount = 0;
    int threeCount = 0;
    int result = -1;
    cin >> target;

    for(int i = 0;;i++){
        int nam = target - i*5;
        if(nam < 0){
            break;
        }
        if(nam % 3 == 0){
            fiveCount = i;
            threeCount = nam / 3;
        }
    }
    if(fiveCount == 0 && threeCount == 0){

    }else{
        result = fiveCount + threeCount;
    }

    cout << result << endl;

    return 0;
}
