#include <iostream>
#define MAX 10001
#define INF 987654321
using namespace std;

int m, n;
bool matrix[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    int cur = 2;
    matrix[1] = true;
    while (cur < n+1)
    {
        if (matrix[cur] == false)
        {
            for (int i = cur * 2; i < n+1; i += cur)
            {
                matrix[i] = true;
            }
        }
        cur++;
    }
    int sum = 0;
    int min = INF;
    for(int i = m; i <= n; i++){
        if(matrix[i] == false){
            sum += i;
            if(min == INF){
                min = i;
            }
        }
    }
    if(min == INF){
        cout << -1 << '\n';
    }else{
        cout << sum << '\n';
        cout << min << '\n';
    }

    return 0;
}