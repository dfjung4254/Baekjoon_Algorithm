#include <iostream>
#define up 0
#define right 1
#define down 2
#define left 3
using namespace std;

int n, m, r, c, d;
int matrix[50][50];
int ret = 0;
bool finish = true;

void goFlush(){
    if(matrix[r][c] == 0){
        matrix[r][c] = -1;
        ret++;
        //cout << "flush : " << r << "," << c << " / ret : " << ret << '\n';
    }
}

bool checkLeft(){
    if(d == up && c > 0 && matrix[r][c-1] == 0){
        return true;
    }else if(d == right && r > 0 && matrix[r-1][c] == 0){
        return true;
    }else if(d == down && c < m-1 && matrix[r][c+1] == 0){
        return true;
    }else if(d == left && r < n-1 && matrix[r+1][c] == 0){
        return true;
    }
    return false;
}

bool checkBack(){
    if(d == up && r < n-1 && matrix[r+1][c] != 1){
        return true;
    }else if(d == right && c > 0 && matrix[r][c-1] != 1){
        return true;
    }else if(d == down && r > 0 && matrix[r-1][c] != 1){
        return true;
    }else if(d == left && c < m-1 && matrix[r][c+1] != 1){
        return true;
    }
    return false;
}

void rotate(){
    if(--d < 0){
        d = 3;
    }
}

void gogo(){
    if(d == up){
        r--;
    }else if(d == right){
        c++;
    }else if(d == down){
        r++;
    }else if(d == left){
        c--;
    }
}

void goBack(){
    if(d == up){
        r++;
    }else if(d == right){
        c--;
    }else if(d == down){
        r--;
    }else if(d == left){
        c++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    while(finish){

        goFlush();
        bool check4Dir = false;
        for(int i = 0; i < 4; i++){
            if(checkLeft()){
                //전진
                rotate();
                gogo();
                check4Dir = true;
                break;
            }else{
                //회전
                rotate();
            }
        }
        if(!check4Dir){
            //후퇴할공간?
            //있으면 후퇴 없으면 중단
            if(checkBack()){
                goBack();
            }else{
                finish = false;
            }
        }
    }
    
    cout << ret << '\n';

    return 0;
}