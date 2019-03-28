#include <iostream>
#include <cmath>
using namespace std;

int n;

int fact(){
    if(n == 0){
        return 0;
    }
    int count_2 = 0;
    int count_5 = 0;
    for (int i = 1; i <= n; i++){
        int curNum = i;
        while(true){
            if(curNum % 2 != 0 && curNum % 5 != 0){
                break;
            }
            if(curNum % 2 == 0){
                count_2++;
                curNum = curNum / 2;
            }
            if(curNum % 5 == 0){
                count_5++;
                curNum = curNum / 5;
            }
        }
    }
    return (count_2 > count_5) ? count_5 : count_2;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cout << fact() << '\n';

    return 0;
}