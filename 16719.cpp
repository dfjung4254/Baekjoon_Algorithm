#include <iostream>
#include <string>
using namespace std;

bool used[101] = {
    false,
};
int strSize;
string input;

int find(int idx)
{
    int ret = 123;
    int retIdx = -1;
    /* idx를 기준으로 오른쪽 존재할 때 까지 */
    for (int i = idx; i < strSize; i++)
    {
        if (used[i])
        {
            break;
        }
        if (ret > input[i])
        {
            ret = input[i];
            retIdx = i;
        }
    }
    return retIdx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> input;
    strSize = input.size();

    int curIdx = -1;
    while (true)
    {
        /*
        
            1. 현재 인덱스에서 오른쪽 구간을 찾아서 최소를 찾는다.
            2. 최소를 찾으면 추가하고(used) 현재 인덱스를 바꿔준 다음 프린트한다.
            3. 루프를 돈다.

            4. 만약 최소를 못찾으면 가장 인접한 왼쪽에 있는 인덱스를 찾아서 위를 반복한다.
        
         */

        /* 오른쪽 중 최소가 존재하는지? */
        if(curIdx == -1 && used[curIdx+1])
        {
            break;
        }
        if (curIdx == strSize - 1 || used[curIdx + 1])
        {
            /* 최소 존재 안함 */
            while(curIdx > -1)
            {
                curIdx--;
                if(curIdx == -1 || used[curIdx])
                {
                    break;
                }
            }
        }
        else
        {
            /* 최소 존재 함 - 루프 돌면서 찾기 */
            int nextMin = find(curIdx + 1);
            used[nextMin] = true;
            curIdx = nextMin;

            /* 출력 */
            for(int i = 0; i < strSize; i++)
            {
                if(used[i])
                {
                    cout << input[i];
                }
            }
            cout << '\n';
        }
    }

    return 0;
}