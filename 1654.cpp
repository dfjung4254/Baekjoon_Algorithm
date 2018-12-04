#include <iostream>
#include <algorithm>
using namespace std;

long long k, n;
long long lan[100000];

int main(){

    cin >> k >> n;
    long long max = 0;
    for(int i = 1; i <= k; i++){
        cin >> lan[i];
        if(lan[i] > max){
            max = lan[i];
        }
    }
    long long right = max;
    long long left = 1;
    long long mid = (right+left)/2;
    while(true){
        int tmp = 0;
        for(int i = 1; i <= k; i++){
            tmp += lan[i]/mid;
        }
        if(tmp >= n){
            left = mid;
            mid = (right+left)/2;
        }else{
            right = mid;
            mid = (right+left)/2;
        }

    }

    return 0;
}
