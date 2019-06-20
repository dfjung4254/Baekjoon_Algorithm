#include <iostream>
#include <cmath>
using namespace std;

int r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r;
    cout << fixed;
    cout.precision(6);
    cout << M_PI * r * r << '\n';
    cout << r * r * 2 << '\n';

    return 0;
}