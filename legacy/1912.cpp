#include <iostream>
using namespace std;

/*

    ������.

*/

int ret = -1001;

void search(int num[], int index, int before, int size){

    if(before > ret){
        ret = before;
    }
    if(index == size){
        //�ڿ����� ���� �ִ븦 ã��
        return;
    }

    if(before+num[index] < 0){
        //�ʱ�ȭ
        search(num, index+1, -1001, size);
    }else{
        //����
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
