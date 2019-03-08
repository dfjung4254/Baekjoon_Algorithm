#include <iostream>
#include <cmath>
using namespace std;

int matrix[100][100];
int n, l;
int ret;

void checkVerticalLine(int _j){
    
}

void checkHorizontalLine(int _i){

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        checkVerticalLine(i);
    }
    for(int i = 0; i < n; i++){
        checkHorizontalLine(i);
    }

    return 0;
}