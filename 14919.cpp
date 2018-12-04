#include <iostream>
#include <iomanip>
using namespace std;

int m;

int main(){
    setprecision(9);
    cin >> m;
    int ans[m] = {0, };
    double l = (double) 1/m;
    do{
        double input;
        cin >> input;
        ans[(int)(input / l + 0.0000000001)]++;
    }while(getchar() == ' ');
    for(int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}
