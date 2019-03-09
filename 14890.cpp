#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int matrix[100][100];
int n, l;
int ret;

bool checkLine(vector<int> line)
{

    bool slideOn[100] = {
        false,
    };
    int before = line[0];
    for (int i = 1; i < line.size(); i++)
    {

        /*

            진행하다 before과 차이나면 체크

        */
        int cur = line[i];
        if (before != cur)
        {

            /* 1 계단 이상 차이 */
            if (abs(before - cur) > 1)
            {
                return false;
            }

            if (before - cur == 1)
            {
                /* 1계단 차이 낮아짐*/
                /* 다리 건설 가능 여부 확인 */
                for (int j = i; j < i + l; j++)
                {
                    /* 인덱스 벗어나는 경우 */
                    if (j >= line.size())
                    {
                        return false;
                    }
                    /* 땅이 고르지 못한 경우 */
                    if (line[j] != cur)
                    {
                        return false;
                    }
                    /* 이미 경사로가 지어진 경우 */
                    if (slideOn[j])
                    {
                        return false;
                    }
                    /* 예외 없을 시 경사로 건설 */
                    slideOn[j] = true;
                }
            }
            else if (cur - before == 1)
            {
                /* 1계단 차이 높아짐*/
                /* 다리 건설 가능 여부 확인 */
                for (int j = i - 1; j > i - 1 - l; j--)
                {
                    /* 인덱스 벗어나는 경우 */
                    if (j < 0)
                    {
                        return false;
                    }
                    /* 땅이 고르지 못한 경우 */
                    if (line[j] != before)
                    {
                        return false;
                    }
                    /* 이미 경사로가 지어진 경우 */
                    if (slideOn[j])
                    {
                        return false;
                    }
                    /* 예외 없을 시 경사로 건설 */
                    slideOn[j] = true;
                }
            }
        }

        before = cur;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for(int j = 0; j < n; j++){
            v.push_back(matrix[i][j]);
        }
        if(checkLine(v)){
            ret++;
        }
    }
    for (int j = 0; j < n; j++)
    {
        vector<int> v;
        for(int i = 0; i < n; i++){
            v.push_back(matrix[i][j]);
        }
        if(checkLine(v)){
            ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}