#include <iostream>
#include <cmath>
using namespace std;

long long n, k;
long long low, high, mid;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    low = 1;
    high = n*n;
    while(low <= high){
        mid = (low + high) / 2;
        long long sc = 0;
        for (int i = 1; i <= n; i++)
        {
            sc += min(mid / i, n);
        }
        if(sc >= k){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    cout << high + 1 << '\n';

    return 0;
}