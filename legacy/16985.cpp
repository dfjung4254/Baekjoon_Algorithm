#include <iostream>
#include <queue>
using namespace std;

/*

    1. 회전 함수를 만든다.
    2. 00000 - 33333 경우의 수를 구한다
    3. 12345 - 54321 판의 위치 경우의 수를 구한다
    4. bfs를 돌린다.
    5. 최소 거리를 구한다.

*/

struct Point
{
    int k, i, j;
};

const int dir_k[6] = {0, 0, 0, 0, -1, 1};
const int dir_i[6] = {-1, 0, 1, 0, 0, 0};
const int dir_j[6] = {0, 1, 0, -1, 0, 0};

/* [층][세로][가로] */
int matrix[5][5][5];
int ret = -1;
queue<Point> q;

int matrix_exec[5][5][5];
bool visited_exec[5][5][5];

void memset_visited()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                visited_exec[i][j][k] = false;
            }
        }
    }
}

void bfs()
{

    /* visited 배열 초기화 */
    memset_visited();

    if(matrix_exec[0][0][0] == 0){
        return;
    }

    q.push({0, 0, 0});
    visited_exec[0][0][0] = true;
    matrix_exec[0][0][0] = 0;
    while (!q.empty())
    {

        Point curPoint = q.front();
        int k = curPoint.k;
        int i = curPoint.i;
        int j = curPoint.j;
        q.pop();

        /* 인접 행렬 find */
        int idx = 0;
        while (idx < 6)
        {

            int tk = k + dir_k[idx];
            int ti = i + dir_i[idx];
            int tj = j + dir_j[idx];
            if ((tk >= 0 && tk < 5) && (ti >= 0 && ti < 5) && (tj >= 0 && tj < 5) && !visited_exec[tk][ti][tj] && matrix_exec[tk][ti][tj] == 1)
            {

                q.push({tk, ti, tj});
                matrix_exec[tk][ti][tj] = matrix_exec[k][i][j] + 1;
                visited_exec[tk][ti][tj] = true;
            }
            idx++;
        }
    }

    if (visited_exec[4][4][4] && (matrix_exec[4][4][4] < ret || ret == -1))
    {
        ret = matrix_exec[4][4][4];
    }
}

void rotateMat(int idx, int rank, int rotate_count)
{

    /* 
        matrix_exec idx번째 판을
        matrix rank번째 판을 rotate_count 만큼 회전시켜 세팅한다.
    */

    switch (rotate_count)
    {
    case 0:
        /* 무회전 */
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matrix_exec[idx][i][j] = matrix[rank][i][j];
            }
        }
        break;
    case 1:
        /* 1회 회전 */
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matrix_exec[idx][i][j] = matrix[rank][4 - j][i];
            }
        }
        break;
    case 2:
        /* 2회 회전 */
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matrix_exec[idx][i][j] = matrix[rank][4 - i][4 - j];
            }
        }
        break;
    case 3:
        /* 3회 회전 */
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matrix_exec[idx][i][j] = matrix[rank][j][4 - i];
            }
        }
        break;
    default:
        break;
    }
}

/* 매트리스 세팅 */
void setMatrix(int rotate[], int rank[])
{

    for (int i = 0; i < 5; i++)
    {
        rotateMat(i, rank[i], rotate[i]);
    }

    bfs();
}

/* 쌓기 경우의 수 */
void caseFind(int rotate[], int rank[], bool visit[], int idx, int num)
{

    rank[idx] = num;
    visit[num] = true;

    bool flag = true;
    for (int i = 0; i < 5; i++)
    {
        if (!visit[i])
        {
            /* 아직 방문하지 않은 경우 방문한다 */
            caseFind(rotate, rank, visit, idx + 1, i);
            flag = false;
            visit[i] = false;
        }
    }

    if (flag)
    {
        /* 케이스 끝 - bfs 돌려본다 */
        setMatrix(rotate, rank);
    }
}

void setRankPosition(int rotate[], int rank[], bool visit[])
{
    for (int i = 0; i < 5; i++)
    {
        /* 아직 방문하지 않은 경우 방문한다 */
        caseFind(rotate, rank, visit, 0, i);
        visit[i] = false;
    }
}

/* 회전 경우의 수 */
void rotateFind(int rotate[], int idx, int num)
{

    if (idx == 5)
    {
        /* 케이스 끝 */
        int rank_case[5] = {
            0,
        };
        bool visit_case[5] = {
            false,
        };
        setRankPosition(rotate, rank_case, visit_case);
        return;
    }

    if (num == 4)
    {
        /* 회전 범위 벗어남 */
        return;
    }

    rotate[idx] = num;

    rotateFind(rotate, idx + 1, 0);
    rotateFind(rotate, idx, num + 1);
}

int main()
{

    /* input */
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> matrix[k][i][j];
            }
        }
    }

    int thisCase[5] = {
        0,
    };
    rotateFind(thisCase, 0, 0);

    cout << ret << '\n';

    return 0;
}