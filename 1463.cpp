#include <iostream>
using namespace std;

/*

    ���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

    1. X�� 3���� ������ ��������, 3���� ������.
    2. X�� 2�� ������ ��������, 2�� ������.
    3. 1�� ����.

    ���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�.
    ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

    �����Է�1
    input : 2
    output : 1

    �����Է�2
    input : 10
    output : 3

    �����Է�3
    input : 100
    output : 7

*/

int maxcount;

void search(int x, int count){
    if(count > maxcount){
        cout << "������ Ž��" << endl;
        return;
    }

    if(x == 1){
        if(maxcount > count){
            maxcount = count;
            cout << "���� : ";
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
