#include <iostream>

using namespace std;

int n, cnt = 0;
bool matrix[15][15] = {
    false,
};
int isOk[15][15];

void checkOk(int row, int col, int flag)
{
    int k = 1;
    for (int i = row + 1; i < n; i++)
    {
        int col1 = col + k;
        int col2 = col - k;
        k++;
        isOk[i][col] += flag;
        if (col1 >= 0 && col1 < n)
        {
            isOk[i][col1] += flag;
        }
        if (col2 >= 0 && col2 < n)
        {
            isOk[i][col2] += flag;
        }
    }
}

void queen(int row, int col)
{

    if (isOk[row][col] == 0)
    {
        if (row == n - 1)
        {
            cnt++;
            return;
        }
        checkOk(row, col, 1);
        for (int i = 0; i < n; i++)
        {
            queen(row + 1, i);
        }
        checkOk(row, col, -1);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            isOk[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        queen(0, i);
    }
    cout << cnt << '\n';

    return 0;
}