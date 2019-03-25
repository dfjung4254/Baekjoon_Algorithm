#include <iostream>
#define ll unsigned long long
using namespace std;

ll find(ll n)
{
    /*
    
        회수를 찍는다.
        mid 는 횟수를 말한다.

    */
    ll low = 1;
    ll high = n;
    ll mid = 0;
    while(low <= high){
        mid = (low + high) / 2;
        ll maxDist
        = (mid % 2 == 0) ? (1 + mid) * (mid / 2) : mid * ((mid - 1) / 2) + mid;
        if(maxDist <= n){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        cout << find(n) << '\n';
    }

    return 0;
}