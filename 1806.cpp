#include <iostream>
using namespace std;

int matrix[100000];
int n, s;
int minimum = 0;

void find(int front, int rear, int sum){
    if(sum < s){
        if(rear == n){
            return;
        }
        find(front, rear+1, sum+matrix[rear+1]);
    }else{
        int tmp = rear-front+1;
        if(minimum > tmp || minimum == 0){
            minimum = tmp;
        }
        if(rear == front == n){
            return;
        }
        find(front+1, rear, sum-matrix[front]);
    }
}

int main(){

    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> matrix[i];
    }
    find(1, 1, matrix[1]);
    cout << minimum << endl;
    return 0;
}
