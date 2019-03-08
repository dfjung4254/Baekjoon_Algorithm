#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
int ret = -1;
char matrix[10][10];
char matrix_exec[10][10];
pair<int, int> p_red;
pair<int, int> p_blue;
pair<int, int> origin_red;
pair<int, int> origin_blue;
vector<char> output;

int dir_i[4] = {-1, 0, 1, 0};
int dir_j[4] = {0, 1, 0, -1};

void tiltBoard(int direction)
{

    /*
    
        1. R, B 중에 direction에 더 가까운 것을 먼저 찾는다.
        2. (R이 더 가까울때) R 을 벽에 닿을때까지 이동시킨다.
        3. 나머지 B 를 R 또는 벽에 닿을때까지 이동시킨다.
        4. 만약 벽에 닿기전에 구멍에 닿는다면 output에 추가시키고 없앤다.
    
    */

    /* 더 가까운 것 찾기 */
    vector<pair<int, int>> ball;
    bool flag = true;
    switch (direction)
    {
    case 0: /* up  - i 값이 더 작은 것 */
        flag = (p_red.first <= p_blue.first) ? true : false;
        break;
    case 1: /* right - j 값이 더 큰 것 */
        flag = (p_red.second >= p_blue.second) ? true : false;
        break;
    case 2: /* down - i 값이 더 큰 것 */
        flag = (p_red.first >= p_blue.first) ? true : false;
        break;
    case 3: /* left -j 값이 더 작은 것 */
        flag = (p_red.second <= p_blue.second) ? true : false;
        break;
    default:
        break;
    }

    char firstb, secondb;
    if (flag)
    {
        firstb = 'R';
        secondb = 'B';
        ball.push_back(p_red);
        ball.push_back(p_blue);
    }
    else
    {
        firstb = 'B';
        secondb = 'R';
        ball.push_back(p_blue);
        ball.push_back(p_red);
    }

    /* 첫번 째 공 벽이나 0에 닿을 때 까지 이동 */
    pair<int, int> thisBall = ball.front();
    int ti = thisBall.first;
    int tj = thisBall.second;
    bool isOutput = false;
    while ((ti + dir_i[direction] >= 0 && ti + dir_i[direction] < 10) && (tj + dir_j[direction] >= 0 && tj + dir_j[direction] < 10) && matrix_exec[ti + dir_i[direction]][tj + dir_j[direction]] != '#')
    {
        ti += dir_i[direction];
        tj += dir_j[direction];
        if (matrix_exec[ti][tj] == 'O')
        {
            /* 구멍에 빠짐 */
            output.push_back(firstb);
            isOutput = true;
            break;
        }
    }
    matrix_exec[thisBall.first][thisBall.second] = '.';
    matrix_exec[ti][tj] = (isOutput) ? 'O' : firstb;

    if (flag)
    {
        p_red.first = ti;
        p_red.second = tj;
    }
    else
    {
        p_blue.first = ti;
        p_blue.second = tj;
    }

    /* 두번 째 공 벽이나 0에 닿을 때 까지 이동 */
    thisBall = ball.back();
    ti = thisBall.first;
    tj = thisBall.second;
    isOutput = false;
    while ((ti + dir_i[direction] >= 0 && ti + dir_i[direction] < 10) && (tj + dir_j[direction] >= 0 && tj + dir_j[direction] < 10) && (matrix_exec[ti + dir_i[direction]][tj + dir_j[direction]] != '#' && matrix_exec[ti + dir_i[direction]][tj + dir_j[direction]] != firstb))
    {
        ti += dir_i[direction];
        tj += dir_j[direction];
        if (matrix_exec[ti][tj] == 'O')
        {
            output.push_back(secondb);
            isOutput = true;
            break;
        }
    }
    matrix_exec[thisBall.first][thisBall.second] = '.';
    matrix_exec[ti][tj] = (isOutput) ? 'O' : secondb;

    if (flag)
    {
        p_blue.first = ti;
        p_blue.second = tj;
    }
    else
    {
        p_red.first = ti;
        p_red.second = tj;
    }

}

void simulate(int arr[])
{

    /* init */
    output.clear();
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix_exec[i][j] = matrix[i][j];
        }
    }
    p_red = origin_red;
    p_blue = origin_blue;

    /* simulate */
    bool isFind = false;
    int i = 0;
    while (i < 10)
    {

        tiltBoard(arr[i]);

        if (output.size() == 1 && output.front() == 'R')
        {
            isFind = true;
            break;
        }
        else if (output.size() == 1 && output.front() == 'B')
        {
            break;
        }
        else if (output.size() == 2)
        {
            break;
        }

        i++;
    }

    /* check */
    if (isFind && (ret == -1 || ret > i+1))
    {
        ret = i+1;
    }

}

void _findCase(int arr[], int idx, int val)
{

    if (idx == 10)
    {
        simulate(arr);
        return;
    }

    arr[idx] = val;

    if (val % 2 == 0)
    {
        _findCase(arr, idx + 1, 1);
        _findCase(arr, idx + 1, 3);
    }
    else
    {
        _findCase(arr, idx + 1, 0);
        _findCase(arr, idx + 1, 2);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /* input */
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'R')
            {
                origin_red.first = i;
                origin_red.second = j;
            }
            else if (matrix[i][j] == 'B')
            {
                origin_blue.first = i;
                origin_blue.second = j;
            }
        }
    }

    int arr[10] = {
        0,
    };

    for (int i = 0; i < 4; i++)
    {
        _findCase(arr, 0, i);
    }

    cout << ret << '\n';

    return 0;
}