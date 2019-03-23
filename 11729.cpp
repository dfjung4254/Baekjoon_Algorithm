#include <iostream>
#include <queue>
using namespace std;

int n;
int count = 0;
queue<pair<int, int>> q;

void hanoi(int size, int cur, int tar){

    /*
    
        옮긴다 -> 제일 밑에부분 빼고 나머지를 현재 위치에서 목표가 아닌 다른 곳으로 옮긴다
        -> 제일 밑에부분을 목표부분으로 옮긴다.
        -> 나머지를 목표부분으로 옮긴다.
    
    */
    int next = 0;
    switch(cur+tar){
        case 3:
        next = 3;
        break;
        case 4:
        next = 2;
        break;
        case 5:
        next = 1;
        break;
        default:
        break;
    }
    if(size == 1){
        q.push(make_pair(cur, tar));
        count++;
        return;
    }

    hanoi(size-1, cur, next);
    hanoi(1, cur, tar);
    hanoi(size-1, next, tar);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    hanoi(n, 1, 3);
    cout << count << '\n';
    while(!q.empty()){
        cout << q.front().first << " " << q.front().second << '\n';
        q.pop();
    }

    return 0;
}