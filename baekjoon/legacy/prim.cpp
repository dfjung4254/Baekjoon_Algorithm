#include <iostream>
#define INF 987654321
using namespace std;

int matrix[6][6];
int n;
int nearest[6];
int dist[6];
int ans = 0;

void primSetting()
{
    // index 1을 기준으로 distance 를 짠다.
    for (int i = 1; i <= n; i++)
    {
        nearest[i] = 1;
        dist[i] = matrix[1][i];
    }
}

void prim()
{

    /*
        n-1번 까지 반복한다. -> n-1 번 하면서 연결할 노드 n 까지 다 연결이 되어있어야 한다.
        1. 현재 dist를 돌면서 가장 작은 dist값의 노드를 얻어낸다.
        2. 가장 작은 dist를 연결시킨다.
        3. 연결한 dist에 맞게 nearest와 dist값을 변경시킨다.
    */
    int cnt = n-1;
    while(cnt--)
    {
        int minimum = INF;
        int vNear = 0;
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] >= 0 && dist[i] < minimum)
            {
                // 2 - 5번 노드까지 돌면서 가장 작은 엣지를 찾는다.
                vNear = i;
                minimum = dist[i];
            }
        }

        ans += dist[vNear];
        dist[vNear] = -1;

        // 연결한 노드와 관련해서 새로 생긴 간선 중 더 작은 것이 있다면 바꾸어 준다.
        for (int i = 2; i <= n; i++)
        {
            if (matrix[vNear][i] < dist[i])
            {
                dist[i] = matrix[vNear][i];
                nearest[i] = vNear;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j] == -1)
            {
                matrix[i][j] = INF;
            }
        }
    }

    primSetting();
    prim();

    cout << ans << '\n';

    return 0;
}