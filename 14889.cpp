#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int matrix[20][20];
int ret = 987654321;
vector<int> teamRed;
vector<int> teamBlue;

void calculate()
{

    int powerRed = 0;
    int powerBlue = 0;

    /* _DEBUG */
    if (teamRed.size() != teamBlue.size())
    {
        cout << "Team Setting Error.." << '\n';
    }

    for (int i = 0; i < teamRed.size() - 1; i++)
    {

        for (int j = i + 1; j < teamRed.size(); j++)
        {

            powerRed += matrix[teamRed.at(i)][teamRed.at(j)];
            powerRed += matrix[teamRed.at(j)][teamRed.at(i)];

            powerBlue += matrix[teamBlue.at(i)][teamBlue.at(j)];
            powerBlue += matrix[teamBlue.at(j)][teamBlue.at(i)];
        }
    }

    int tpRet = abs(powerRed - powerBlue);
    if (ret > tpRet)
    {
        ret = tpRet;
    }
}

void setTeam(int arr[], int size)
{

    teamRed.clear();
    teamBlue.clear();

    bool checked[20] = {
        false,
    };

    /* 0번 인덱스는 레드팀 고정이다 */
    teamRed.push_back(0);
    checked[0] = true;

    /* 레드 팀 배정 */
    for (int i = 0; i < size; i++)
    {
        teamRed.push_back(arr[i]);
        checked[arr[i]] = true;
    }

    /* 나머지 블루 팀 배정 */
    for (int i = 0; i < n; i++)
    {
        if (!checked[i])
        {
            teamBlue.push_back(i);
        }
    }

    /* _DEBUG */
    // cout << "RED : ";
    // auto red = teamRed.begin();
    // while (red != teamRed.end())
    // {
    //     cout << *red << " ";
    //     red++;
    // }
    // cout << '\n';
    // cout << "BLUE : ";
    // auto blue = teamBlue.begin();
    // while (blue != teamBlue.end())
    // {
    //     cout << *blue << " ";
    //     blue++;
    // }
    // cout << '\n';
    calculate();
}

void comb(int arr[], int _n, int _r, int idx, int val)
{

    if (idx >= _r)
    {
        /* 조합 완료 */
        setTeam(arr, _r);
        return;
    }

    if (val > _n)
    {
        return;
    }

    arr[idx] = val;

    comb(arr, _n, _r, idx + 1, val + 1);
    comb(arr, _n, _r, idx, val + 1);
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
            cin >> matrix[i][j];
        }
    }

    int arr[20];
    comb(arr, n - 1, n / 2 - 1, 0, 1);

    cout << ret << '\n';

    return 0;
}