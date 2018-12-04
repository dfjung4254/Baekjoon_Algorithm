#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Camera;

int ret = 65;
int n, m;
int cameraNum = 0;
Camera *camera;
int matrix[9][9] = {0, };
int testMatrix[9][9] = {0, };
int directx[] = {1,0,-1,0};
int directy[] = {0,-1,0,1};
int cameraDirection[9] = {0, };
//0 right
//1 up
//2 left
//3 down

void look(int direction, int x, int y){
    int tx = x;
    int ty = y;
    while(true){
        if(tx > m || ty > n || tx < 1 || ty < 1
        || matrix[ty][tx] == 6){
            break;
        }
        testMatrix[ty][tx] = 7;
        tx += directx[direction];
        ty += directy[direction];
    }
}

class Camera{
public:
    int no;
    int x;
    int y;
    Camera(int cameraNo = 0, int x = 0, int y = 0):no(cameraNo),x(x),y(y){}
    void check(int direction){//direction 0,1,2,3
        if(no == 1){
            //camera 1 operation
            look(direction, x, y);
        }else if(no == 2){
            //camera 2 operation
            look(direction, x, y);
            look((direction+2)%4, x, y);
        }else if(no == 3){
            //camera 3 operation
            look(direction, x, y);
            look((direction+1)%4, x, y);
        }else if(no == 4){
            //camera 4 operation
            look(direction, x, y);
            look((direction+1)%4, x, y);
            look((direction+2)%4, x, y);
        }else if(no == 5){
            //camera 5 operation
            look(direction, x, y);
            look((direction+1)%4, x, y);
            look((direction+2)%4, x, y);
            look((direction+3)%4, x, y);
        }
    }
};

void initTestMatrix(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            testMatrix[i][j] = matrix[i][j];
        }
    }
}

void comb(int index, int num){
    if(index > cameraNum){
        //여기서 데이터 테스트
        initTestMatrix();
        // cout << "cameraDirection : ";
        // for(int i = 1; i <= cameraNum; i++){
        //     cout << cameraDirection[i] << " ";
        // }
        // cout << endl;
        for(int i = 1; i <= cameraNum; i++){
            camera[i].check(cameraDirection[i]);
        }
        int count = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
//                cout << testMatrix[i][j] << " ";
                if(testMatrix[i][j] == 0){
                    count++;
                }
            }
//            cout << '\n';
        }
//        cout << '\n';
        if(count < ret){
            ret = count;
        }
        return;
    }
    if(num > 3){
        return;
    }
    cameraDirection[index] = num;
    comb(index+1, 0);
    comb(index, num+1);
}

int main(){

    cin >> n >> m;
    camera = new Camera[9];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int k;
            cin >> k;
            matrix[i][j] = k;
            if(k != 0 && k != 6){
                cameraNum++;
                camera[cameraNum].no = k;
                camera[cameraNum].x = j;
                camera[cameraNum].y = i;
            }
        }
    }
//    cout << endl;
    comb(1, 0);
    cout << ret << endl;

    delete[] camera;
    return 0;
}
