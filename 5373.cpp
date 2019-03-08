#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int i, j;
};

struct Border
{
    int next[4];
    Point point[4][3];
};

class Cube
{
  public:
    /* U, D, F, B, L, R */
    char matrix[6][3][3];
    char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
    enum
    {
        U,
        D,
        F,
        B,
        L,
        R
    };

    Border border[6] = {
        {/* border 0 */
         {3, 5, 2, 4},
         {
             {{2, 0}, {2, 1}, {2, 2}},
             {{0, 0}, {1, 0}, {2, 0}},
             {{0, 2}, {0, 1}, {0, 0}},
             {{2, 2}, {1, 2}, {0, 2}},
         }},
        {/* border 1 */
         {2, 5, 3, 4},
         {
             {{2, 0}, {2, 1}, {2, 2}},
             {{2, 2}, {1, 2}, {0, 2}},
             {{0, 2}, {0, 1}, {0, 0}},
             {{0, 0}, {1, 0}, {2, 0}},
         }},
        {/* border 2 */
         {0, 5, 1, 4},
         {
             {{2, 0}, {2, 1}, {2, 2}},
             {{2, 0}, {2, 1}, {2, 2}},
             {{0, 2}, {0, 1}, {0, 0}},
             {{2, 0}, {2, 1}, {2, 2}},
         }},
        {/* border 3 */
         {1, 5, 0, 4},
         {
             {{2, 0}, {2, 1}, {2, 2}},
             {{0, 2}, {0, 1}, {0, 0}},
             {{0, 2}, {0, 1}, {0, 0}},
             {{0, 2}, {0, 1}, {0, 0}},
         }},
        {/* border 4 */
         {3, 0, 2, 1},
         {
             {{0, 0}, {1, 0}, {2, 0}},
             {{0, 0}, {1, 0}, {2, 0}},
             {{0, 0}, {1, 0}, {2, 0}},
             {{0, 0}, {1, 0}, {2, 0}},
         }},
        {/* border 5 */
         {3, 1, 2, 0},
         {
             {{2, 2}, {1, 2}, {0, 2}},
             {{2, 2}, {1, 2}, {0, 2}},
             {{2, 2}, {1, 2}, {0, 2}},
             {{2, 2}, {1, 2}, {0, 2}},
         }},
    };

    Cube()
    {
        /* 색상 초기화 */
        for (int k = 0; k < 6; k++)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    matrix[k][i][j] = color[k];
                }
            }
        }
    }

    void exec_cube(char _border, char _direction);
    void print_cube();
    int charToInt_border(char border);
    bool charToBool_direction(char direction);
};

void Cube::exec_cube(char _border, char _direction)
{

    int cur_border = charToInt_border(_border);
    bool cur_direction = charToBool_direction(_direction);

    /* 면 4개를 각각 direction에 따라 3줄씩 swap 시킨다 */
    /* 임시 보드 저장 */
    char matrix_buffer[6][3][3];
    for (int i = 0; i < 4; i++)
    {
        for (int pt = 0; pt < 3; pt++)
        {
            /* 현재 보드 */
            int tp_board = border[cur_border].next[i];
            Point tp_point = border[cur_border].point[i][pt];

            /* 다음 보드 */
            int next_idx = 0;
            if (cur_direction)
            { // 시계방향
                next_idx = (i + 3) % 4;
            }
            else
            { // 반시계방향
                next_idx = (i + 1) % 4;
            }
            int tp_board_next = border[cur_border].next[next_idx];
            Point tp_point_next = border[cur_border].point[next_idx][pt];

            matrix_buffer[tp_board][tp_point.i][tp_point.j] = matrix[tp_board_next][tp_point_next.i][tp_point_next.j];
        }
    }

    /* 버퍼에 담은 색 실제 큐브 삽입 */
    for (int i = 0; i < 4; i++)
    {
        for (int pt = 0; pt < 3; pt++)
        {
            /* 현재 보드 */
            int tp_board = border[cur_border].next[i];
            Point tp_point = border[cur_border].point[i][pt];

            matrix[tp_board][tp_point.i][tp_point.j] = matrix_buffer[tp_board][tp_point.i][tp_point.j];
        }
    }

    /* 현재 면을 direction 에 따라 회전 시킨다. */
    /* 버퍼 저장 */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (cur_direction)
            {
                matrix_buffer[cur_border][i][j] = matrix[cur_border][2 - j][i];
            }
            else
            {
                matrix_buffer[cur_border][i][j] = matrix[cur_border][j][2 - i];
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[cur_border][i][j] = matrix_buffer[cur_border][i][j];
        }
    }
    
}

void Cube::print_cube()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[Cube::U][i][j];
        }
        cout << '\n';
    }
}

int Cube::charToInt_border(char border)
{
    switch (border)
    {
    case 'U':
        return 0;
        break;
    case 'D':
        return 1;
        break;
    case 'F':
        return 2;
        break;
    case 'B':
        return 3;
        break;
    case 'L':
        return 4;
        break;
    case 'R':
        return 5;
        break;
    default:
        return -1;
        break;
    }
}

bool Cube::charToBool_direction(char direction)
{
    switch (direction)
    {
    case '+':
        return true;
        break;
    case '-':
        return false;
        break;
    default:
        return true;
        break;
    }
}

Cube *cube;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {

        /* 큐브 리셋 */
        cube = new Cube();
        /* 입력 */
        int n;
        cin >> n;
        string command;
        while (n--)
        {
            char border, direction;
            cin >> border;
            cin >> direction;

            cube->exec_cube(border, direction);
        }

        cube->print_cube();
        delete cube;
    }

    return 0;
}