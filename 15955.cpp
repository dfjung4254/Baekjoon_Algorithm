#include <iostream>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;

int n, cmd;
vector<pair<int, int>> checkPoint;
queue<int> q;

bool isAvailable(int curCP, int tarCP, int dist){

    /* 현재 체크포인트에서 해당 체크 포인트 갈 수 있나 검사 */
    /*

        1. 그냥 걸어서 도달한다.
        2. 걸어서 목표 체크포인트의 x좌표나 y 좌표로 간다. - 부스터를 쓴다

    */

    int curX = checkPoint[curCP].x;
    int curY = checkPoint[curCP].y;
    int tarX = checkPoint[tarCP].x;
    int tarY = checkPoint[tarCP].y;

    int minX = curX - dist;
    int maxX = curX + dist;
    int minY = curY - dist;
    int maxY = curY + dist;

    /* tarX 나 tarY 중 하나만 범위 사이에 있으면 된다 */
    if((tarX >= minX && tarX <= maxX) || (tarY >= minY && tarY <= maxY)){
        return true;
    }
    return false;
}

bool simulate(int cp1, int cp2, int mHp, bool visited[]){


    /*
    
        현재 체크포인트에서 도달 할 수 있는 
        체크포인트들을 기준으로 BFS 를 수행한다.
    */

    int checkSize = checkPoint.size();
    
    q.push(cp1);
    visited[cp1] = true;
    bool ret = false;
    while(!q.empty()){
        int curCh = q.front();
        q.pop();
        for(int i = 1; i < checkSize; i++){
            if(!visited[i] && isAvailable(curCh, i, mHp)){
                /* 방문 안했고 도달 가능하면 방문 */
                q.push(i);
                visited[i] = true;
                if(i == cp2){
                    ret = true;
                    while(!q.empty()){
                        q.pop();
                    }
                    break;
                }
            }
        }
    }
    return ret;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /* empty check for index count */
    checkPoint.push_back(make_pair(0, 0));

    cin >> n >> cmd;
    while(n--){
        int _x, _y;
        cin >> _x >> _y;
        checkPoint.push_back(make_pair(_x, _y));
    }

    while(cmd--){
        /* 방문 기록 초기화 */
        bool visit[250001] = {false, };
        int check1, check2, maxHp;
        cin >> check1 >> check2 >> maxHp;
        if(simulate(check1, check2, maxHp, visit)){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }

    return 0;
}