#include <iostream>
#include <queue>
#define N_MAX 101
using namespace std;

int n;
int matrix[N_MAX][N_MAX] = {0, };
enum OBJECT{
    BLANK, SNAKE, APPLE
};
enum DIRECTION{
    UP, RIGHT, DOWN, LEFT
};
const int dir_i[4] = {-1, 0, 1, 0};
const int dir_j[4] = {0, 1, 0, -1};
int ans = 0;

class Snake{
public:
    bool isAlive;
    int direction;
    int mov_count; /* 이동횟수 = 시간 */
    pair<int, int> head_point;
    queue<pair<int, int>> body;
    Snake(){
        isAlive = true;
        mov_count = 0;
        direction = DIRECTION::RIGHT;
        head_point = make_pair(1, 1);
        body.push(head_point);
    }
    void move();
};

void Snake::move(){

    /* 이동횟수 갱신 */
    mov_count++;

    if(!isAlive){
        return;
    }

    /* 현재 direction과 head_point 를 기준으로 다음 좌표를 탐색 */
    int next_i = head_point.first + dir_i[direction];
    int next_j = head_point.second + dir_j[direction];

    /* 다음 좌표의 유효성 검사 */
    if(next_i < 1 || next_i > n || next_j < 1 || next_j > n){
        isAlive = false;
        ans = mov_count;
        return;
    }

    if(matrix[next_i][next_j] == SNAKE){
        isAlive = false;
        ans = mov_count;
        return;
    }

    /* 다음 좌표로 전진 */
    body.push(make_pair(next_i, next_j));
    head_point.first = next_i;
    head_point.second = next_j;

    /* 사과가 없을 경우 */
    if(matrix[next_i][next_j] == BLANK){
        matrix[body.front().first][body.front().second] = BLANK;
        body.pop();
    }

    /* 머리 그려줌 */
    matrix[next_i][next_j] = SNAKE;

}

void operateSnake(Snake *snake, int sec, char dir){

    /* 주어진 sec 동안 현재 방향대로 전진 시킨다. */
    while(snake->mov_count < sec){
        snake->move();
    }

    /* 뱀의 현재 머리방향을 dir로 바꾸어 준다 */
    switch(dir){
        case 'D': /* 진행 방향 오른쪽 */
        snake->direction = (snake->direction+1) % 4;
        break;
        case 'L': /* 진행 방향 왼쪽 */
        snake->direction = (snake->direction+3) % 4;
        break;
        default:
        break;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /* input */
    cin >> n;
    int apple;
    cin >> apple;
    while(apple--){
        int tpI, tpJ;
        cin >> tpI >> tpJ;
        matrix[tpI][tpJ] = OBJECT::APPLE;
    }
    
    Snake *snake = new Snake();
    matrix[1][1] = SNAKE;
    int cmd = 0;
    cin >> cmd;
    vector<pair<int, char>> cmds;
    while(cmd--){
        int sec;
        char dir;
        cin >> sec >> dir;
        cmds.push_back(make_pair(sec, dir));
    }

    for(pair<int, char> pa : cmds){
        operateSnake(snake, pa.first, pa.second);
    }

    while(snake->isAlive){
        snake->move();
    }

    cout << ans << '\n';

    return 0;
}