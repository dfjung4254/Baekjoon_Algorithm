#include <iostream>
#include <vector>
using namespace std;

long long a, b, v;
long long low, high;

long long find(){

    while(low <= high){

        long long mid = (low + high) / 2;
        long long day = a * mid - b * (mid - 1);
        if(day < v){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return low;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> v;
    low = 1;
    high = v;

    cout << find() << '\n';

    return 0;
}