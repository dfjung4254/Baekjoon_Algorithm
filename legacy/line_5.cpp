#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Brown{
    int time, pos;
};

int c, b;
vector<int> cPos;
int ret = -1;
queue<Brown> q;

void bfs(){

    /*

        bfs를 돌리는데 조건이 있다.
        브라운이 코니를 앞지르면 되는것.
        

    */

    q.push({0, b});


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> b;
    cPos.push_back(c);
    int st = 1;
    /*

    턴 당 코니의 위치를 계산한다.

    */
    while(cPos.back() <= 200000){
        int current = cPos.back();
        int next = current + st++;
        cPos.push_back(next);
    }

    bfs();

    return 0;
}