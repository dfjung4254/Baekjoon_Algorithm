#include <iostream>
using namespace std;

int spd, tgSpd, dist;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> spd >> tgSpd >> dist;

    cout << dist / (spd * 2) * tgSpd << '\n';

    return 0;
}