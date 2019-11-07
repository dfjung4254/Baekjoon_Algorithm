#include <iostream>
using namespace std;

int main(){

    int month;
    int date;
    cin >> month >> date;

    int maxDate = 0;
    for(int i = 1; i < month; i++){
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10
        || i == 12){
            maxDate += 31;
        }else if(i == 2){
            maxDate += 28;
        }else{
            maxDate += 30;
        }
    }
    maxDate += date;
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int target = maxDate % 7;
    cout << day[target] << endl;

    return 0;
}
