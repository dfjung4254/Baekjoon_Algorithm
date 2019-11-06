#include <iostream>
#include <vector>
using namespace std;

int n;
int matrix[2187][2187] = {
    0,
};
int count_m1 = 0;
int count_0 = 0;
int count_1 = 0;

void inline dConquer(int size, int iOffset, int jOffset)
{

    int i_end = iOffset + size;
    int j_end = jOffset + size;

    /* 현재 영역이 통일되어 있나 검사 */
    bool isSame = true;
    int num = matrix[iOffset][jOffset];
    for (int i = iOffset; i < i_end; i++)
    {
        for (int j = jOffset; j < j_end; j++)
        {
            if (matrix[i][j] != num)
            {
                isSame = false;
            }
        }
    }

    /* 같으면 카운트, 다르면 분할 */
    if (isSame)
    {
        switch (num)
        {
        case -1:
            count_m1++;
            break;
        case 0:
            count_0++;
            break;
        case 1:
            count_1++;
            break;
        default:
            break;
        }
    }
    else
    {
        int nSize = size / 3;
        int i_offset_1 = iOffset + nSize;
        int i_offset_2 = i_offset_1 + nSize;
        int j_offset_1 = jOffset + nSize;
        int j_offset_2 = j_offset_1 + nSize;
        /* 원인 -> 배열은 레지스터가 아니라 메모리 참조인데 이렇게하면 메모리 직접참조 많이함
        레지스터로 접근해야함 */
        dConquer(nSize, iOffset, jOffset);
        dConquer(nSize, iOffset, j_offset_1);
        dConquer(nSize, iOffset, j_offset_2);
        dConquer(nSize, i_offset_1, jOffset);
        dConquer(nSize, i_offset_1, j_offset_1);
        dConquer(nSize, i_offset_1, j_offset_2);
        dConquer(nSize, i_offset_2, jOffset);
        dConquer(nSize, i_offset_2, j_offset_1);
        dConquer(nSize, i_offset_2, j_offset_2);
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
            int tp;
            cin >> tp;
            matrix[i][j] = tp;
        }
    }

    dConquer(n, 0, 0);
    cout << count_m1 << '\n';
    cout << count_0 << '\n';
    cout << count_1 << '\n';

    return 0;
}