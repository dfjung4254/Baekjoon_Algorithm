#include <iostream>
using namespace std;

int n, m, h;
int matrix[31][11];
int testMatrix[31][11];

void initTestMatrix(){
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= n; j++){
            testMatrix[i][j] = matrix[i][j];
        }
    }
}

bool goDown(){
    for(int start = 1; start <= n; start++){
        int cur_i = 1;
        int cur_j = start;
        while(true){
            if(cur_i == h+1){
                break;
            }
            if(testMatrix[cur_i][cur_j] != 0){
                if(testMatrix[cur_i][cur_j+1] == testMatrix[cur_i][cur_j]){
                    //right
                    cur_j++;
                }else if(testMatrix[cur_i][cur_j-1] == testMatrix[cur_i][cur_j]){
                    //left
                    cur_j--;
                }
            }
            cur_i++;
        }
        if(cur_j!=start){
            return false;
        }
    }
    return true;
}

int find(){
    //0개 조작
    initTestMatrix();
    if(goDown()){
        return 0;
    }
    //1개 조작
    for(int i = 1; i <= n*h; i++){
        if(i%n != 0 && matrix[i/n+1][i%n] == 0 && matrix[i/n+1][((i+1)%n == 0) ? n:(i+1)%n] == 0){
            initTestMatrix();
            testMatrix[i/n+1][i%n] = n*h+i;
            testMatrix[i/n+1][((i+1)%n == 0) ? n:(i+1)%n] = n*h+i;
            if(goDown()){
                return 1;
            }
        }
    }
    //2개 조작
    for(int i = 1; i <= n*h-1; i++){
        if(i%n != 0 && matrix[i/n+1][i%n] == 0 && matrix[i/n+1][((i+1)%n == 0) ? n:(i+1)%n] == 0){
            for(int j = i+1; j <= n*h; j++){
                if(j%n != 0 && matrix[j/n+1][j%n] == 0 && matrix[j/n+1][((j+1)%n == 0) ? n:(j+1)%n] == 0){
                    initTestMatrix();
                    testMatrix[i/n+1][i%n] = n*h+i;
                    testMatrix[i/n+1][((i+1)%n == 0) ? n:(i+1)%n] = n*h+i;
                    testMatrix[j/n+1][j%n] = n*h+j;
                    testMatrix[j/n+1][((j+1)%n == 0) ? n:(j+1)%n] = n*h+j;
                    if(goDown()){
                        return 2;
                    }
                }
            }
        }
    }
    //3개 조작
    for(int i = 1; i <= n*h-2; i++){
        if(i%n != 0 && matrix[i/n+1][i%n] == 0 && matrix[i/n+1][((i+1)%n == 0) ? n:(i+1)%n] == 0){
            for(int j = i+1; j <= n*h-1; j++){
                if(j%n != 0 && matrix[j/n+1][j%n] == 0 && matrix[j/n+1][((j+1)%n == 0) ? n:(j+1)%n] == 0){
                    for(int k = j+1; k <= n*h; k++){
                        if(k%n != 0 && matrix[k/n+1][k%n] == 0 && matrix[k/n+1][((k+1)%n == 0) ? n:(k+1)%n] == 0){
                            initTestMatrix();
                            testMatrix[i/n+1][i%n] = n*h+i;
                            testMatrix[i/n+1][((i+1)%n == 0) ? n:(i+1)%n] = n*h+i;
                            testMatrix[j/n+1][j%n] = n*h+j;
                            testMatrix[j/n+1][((j+1)%n == 0) ? n:(j+1)%n] = n*h+j;
                            testMatrix[k/n+1][k%n] = n*h+k;
                            testMatrix[k/n+1][((k+1)%n == 0) ? n:(k+1)%n] = n*h+k;
                            if(goDown()){
                                return 3;
                            }
                        }
                    }
                }
            }
        }
    }
   return -1;
}

int main(){

    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        matrix[a][b] = i+1;
        matrix[a][b+1] = i+1;
    }
    cout << find() << endl;

    return 0;
}
