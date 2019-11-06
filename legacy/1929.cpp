#include <iostream>
#include <cstdlib>
using namespace std;

bool matrix[10000001] = {false, };

void check(int cur , int target, int min){

    if(cur > target){
        return;
    }
    if(matrix[cur] == false){
        if(cur >= min){
            printf("%d\n", cur);
        }
        int i = 2;
        while(true){
            if(cur*i > target){
                break;
            }
            matrix[cur*i] = true;
            i++;
        }
        check(cur+1, target, min);
    }else{
        check(cur+1, target, min);
    }

}

int main(){
    int m, n;
    cin >> m >> n;

    check(2, n, m);

    return 0;
}
