#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n, m, h; // ����, ����
int matrix[300][11];
int testMatrix[300][11];

void initMatrix(){
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= n; j++){
            testMatrix[i][j] = matrix[i][j];
        }
    }
}

int goDown(int start){

    initMatrix();
    int cur_i = 1;
    int cur_j = start;
    cout << start << " �� �� �̵� :" << " ";
    while(true){
        //���� ���� ������ h+1�̸� break�ؼ� while�� ���������� ���ΰ� ��ȯ

        //���� �¿츦 ���ɴ�

        //�¿��߿� 1�� ������ ������ �̵��ϰ� �� ������ 0���� ��ȯ

        //�¿쿡 1�� ������ ������ ��ĭ������
        cout << cur_j << " ";
        if(cur_i == h+1){
            //����
            break;
        }
        if(testMatrix[cur_i][cur_j] != 0){
            if(testMatrix[cur_i][cur_j-1] == testMatrix[cur_i][cur_j]){
                //left
                testMatrix[cur_i][cur_j-1] = 0;
                testMatrix[cur_i][cur_j] = 0;
                cur_j--;
            }
            if(testMatrix[cur_i][cur_j+1] == testMatrix[cur_i][cur_j]){
                //right
                testMatrix[cur_i][cur_j+1] = 0;
                testMatrix[cur_i][cur_j] = 0;
                cur_j++;
            }
        }
        cur_i++;
    }
    cout << endl;
    return cur_j;
}

int main(){

    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        matrix[a][b] = i+1;
        matrix[a][b+1] = i+1;
    }
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 1; i <= n; i++){
        cout << goDown(i) << " ";
    }
    cout << endl;

    return 0;
}
