#include <cstdio>
typedef unsigned long long ll;
ll chk(ll x)
{
    return x * (x + 1LL);
}
int main()
{
    int t;
    for (scanf("%d", &t); t > 0; t--)
    {
        ll n;
        scanf("%llu", &n);
        ll low = 1LL, high = n, mid = 1LL;
        while (low <= high)
        {
            mid = (low + high) / 2LL;
            if (chk(mid) > n * 2)
            {
                high = mid - 1LL;
            }else{
                low = mid + 1LL;
            }
            if (chk(mid) > n * 2){
                mid--;
            }
        }
        printf("%llu\n", mid);
    }
    return 0;
}