#include <iostream>
using namespace std;

/*

    정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

    1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
    2. X가 2로 나누어 떨어지면, 2로 나눈다.
    3. 1을 뺀다.

    정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
    연산을 사용하는 횟수의 최솟값을 출력하시오.

    예제입력1
    input : 2
    output : 1

    예제입력2
    input : 10
    output : 3

    예제입력3
    input : 100
    output : 7

*/

int maxcount;

void search(int x, int count){
    if(count > maxcount){
        cout << "끝까지 탐색" << endl;
        return;
    }

    if(x == 1){
        if(maxcount > count){
            maxcount = count;
            cout << "갱신 : ";
            cout << count << endl;
        }
        return;
    }

    if(x % 3 == 0){
        search(x/3, count+1);
        if(x % 2 == 0){
            search(x/2, count+1);
        }
        search(x-1, count+1);
    }else if(x % 2 == 0){
        search(x/2, count+1);
        search(x-1, count+1);
    }else{
        search(x-1, count+1);
    }

}

int main(){

    int target;
    cin >> target;
    maxcount = target;
    search(target, 0);

    cout << maxcount << endl;

    return 0;
}
