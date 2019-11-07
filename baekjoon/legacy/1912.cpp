#include <iostream>
using namespace std;

/*

    실패함.

*/

int ret = -1001;

void search(int num[], int index, int before, int size){

    if(before > ret){
        ret = before;
    }
    if(index == size){
        //뒤에부터 빼서 최대를 찾음
        return;
    }

    if(before+num[index] < 0){
        //초기화
        search(num, index+1, -1001, size);
    }else{
        //진행
        search(num, index+1, before+num[index], size);
    }


}

int main(){

    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    search(num, 0, -1001, n);

    cout << ret << endl;

    return 0;
}
