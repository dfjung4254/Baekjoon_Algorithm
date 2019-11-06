#include <iostream>

using namespace std;

int n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int n0 = 1, n1 = 1, tp;

    while (n--) {
        tp = n1;
        n1 = (n1 + n0 * 2) % 10007;
        n0 = tp;
    }

    cout << n0 << '\n';

    return 0;
}