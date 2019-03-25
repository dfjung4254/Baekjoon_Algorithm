#include <iostream>
using namespace std;

int n;
struct House
{
    int rgb[3];
};
House matrix[1000];
int colored[1000];
int ans = 987654321;

void dp(int colored[], int curColor, int index, int sum){

    if(index >= n){
        /* 완료 */
        if(ans > sum){
            ans = sum;
        }
        return;
    }

    colored[index] = curColor;
    sum += matrix[index].rgb[curColor];

    int nextC1 = (curColor + 1) % 3;
    int nextC2 = (curColor + 2) % 3;

    dp(colored, nextC1, index + 1, sum);
    dp(colored, nextC2, index + 1, sum);

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int _r, _g, _b;
        cin >> _r >> _g >> _b;
        matrix[i].rgb[0] = _r;
        matrix[i].rgb[1] = _g;
        matrix[i].rgb[2] = _b;
    }

    for (int i = 0; i < 3; i++)
    {
        dp(colored, i, 0, 0);
    }
    cout << ans << '\n';

    return 0;
}
