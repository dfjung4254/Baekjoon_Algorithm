#include <iostream>
using namespace std;

int count = 0;

void search(int cur, int target){

    if(cur == target){
        count++;
        return;
    }

    if(cur+1 <= target){
        search(cur+1, target);
    }
    if(cur+2 <= target){
        search(cur+2, target);
    }
    if(cur+3 <= target){
        search(cur+3, target);
    }

}

int main(){

    int n;
    cin >> n;
    int ret[n];
    for(int i = 0; i < n; i++){
        count = 0;
        int input;
        cin >> input;
        search(0, input);
        ret[i] = count;
    }
    for(int i = 0; i < n; i++){
        cout << ret[i] << '\n';
    }

    return 0;
}
