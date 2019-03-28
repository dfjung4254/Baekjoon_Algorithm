#include <iostream>
#define ll unsigned long long
using namespace std;

ll comb(ll n, ll r)
{

    if(r > n-r){
        r = n - r;
    }

    ll up = 1;
    ll down = 1;
    ll j = 1;
    ll offset = n - r;
    for (ll i = n; i > offset; i--)
    {
        up *= i;
        up /= j++;
    }

    return up;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        int n, r;
        cin >> n >> r;
        if (n == 0 && r == 0)
        {
            break;
        }
        cout << comb(n, r) << '\n';
    }

    return 0;
}