#include <iostream>
using namespace std;

int cycle(int init, int count, int newNum){

    if(init == newNum && count != 0){
        cout << count << endl;
        return count;
    }

//    cout << init << " / " << count << " / " << newNum << endl;
    int a = newNum / 10;
    int b = newNum % 10;
    int c = a + b;
    int changeNum = (b * 10) + (c % 10);

    cycle(init, count+1, changeNum);

}

int main(){

    int input;
    cin >> input;
    cycle(input, 0, input);

    return 0;
}
