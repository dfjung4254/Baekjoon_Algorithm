#include <iostream>
using namespace std;

int n, m;
int matrix[20][20];

class Dice
{
  public:
    /* up, down, front, back, left, right */
    int r, c;
    int board[6] = {
        0,
    };
    enum
    {
        UP,
        DOWN,
        FRONT,
        BACK,
        LEFT,
        RIGHT
    };
    /* right, left, up, down */
    int dir_i[5] = {-9, 0, 0, -1, 1};
    int dir_j[5] = {-9, 1, -1, 0, 0};
    Dice() {}

    bool move(int direction);
    void printUp();
    void update();
};

void Dice::printUp()
{
    cout << board[Dice::UP] << '\n';
}

bool Dice::move(int direction)
{

    int next_i = r+dir_i[direction];
    int next_j = c+dir_j[direction];

    /* 범위 체크 */
    if(!(next_i >= 0 && next_i < n && next_j >= 0 && next_j < m)){
        return false;
    }

    /* 주사위 좌표 변경 */
    r = next_i;
    c = next_j;

    /* 주사위 6면 변경 */
    int board_buffer[6];
    switch (direction)
    {
    case 1: // right
        board_buffer[0] = board[4];
        board_buffer[1] = board[5];
        board_buffer[2] = board[2];
        board_buffer[3] = board[3];
        board_buffer[4] = board[1];
        board_buffer[5] = board[0];
        break;
    case 2: // left
        board_buffer[0] = board[5];
        board_buffer[1] = board[4];
        board_buffer[2] = board[2];
        board_buffer[3] = board[3];
        board_buffer[4] = board[0];
        board_buffer[5] = board[1];
        break;
    case 3: // up
        board_buffer[0] = board[2];
        board_buffer[1] = board[3];
        board_buffer[2] = board[1];
        board_buffer[3] = board[0];
        board_buffer[4] = board[4];
        board_buffer[5] = board[5];
        break;
    case 4: // down
        board_buffer[0] = board[3];
        board_buffer[1] = board[2];
        board_buffer[2] = board[0];
        board_buffer[3] = board[1];
        board_buffer[4] = board[4];
        board_buffer[5] = board[5];
        break;
    default:
        break;
    }
    board[0] = board_buffer[0];
    board[1] = board_buffer[1];
    board[2] = board_buffer[2];
    board[3] = board_buffer[3];
    board[4] = board_buffer[4];
    board[5] = board_buffer[5];

    return true;
}

void Dice::update()
{
    /* 현재 상태 매트릭스와 주사위의 위치를 고려하여 숫자 변경 */
    if(matrix[r][c] == 0){
        /* 바닥에 주사위 복사 */
        matrix[r][c] = board[Dice::DOWN];
    }else{
        /* 바닥숫자는 0이되고 주사위의 숫자가 바닥 숫자가 됨 */
        board[Dice::DOWN] = matrix[r][c];
        matrix[r][c] = 0;
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Dice dice;
    int commands;

    /* input */
    cin >> n >> m >> dice.r >> dice.c >> commands;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    while (commands--)
    {
        int dir;
        cin >> dir;
        if(dice.move(dir)){
            dice.update();
            dice.printUp();
        }
    }

    return 0;
}