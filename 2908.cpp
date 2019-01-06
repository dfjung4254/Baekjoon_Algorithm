#include <iostream>
using namespace std;

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int cn = 0, cm = 0, tp;
    tp = n/100;
    n -= tp*100;
    cn += tp;
    tp = n/10;
    n -= tp*10;
    cn += tp*10;
    cn += n*100;
    
    tp = m/100;
    m -= tp*100;
    cm += tp;
    tp = m/10;
    m -= tp*10;
    cm += tp*10;
    cm += m*100;

    if(cn > cm)
        cout << cn << '\n';
    else
        cout << cm << '\n';

    return 0;
}