#include <iostream>
#include <queue>
using namespace std;

int memo[1001];

int search(long cur){

    if(cur == 1){
        return 1;
    }else if(cur == 2){
        return 2;
    }else{
        if(memo[cur] != 0){
            return memo[cur];
        }else{
            memo[cur] = search(cur-1) + search(cur-2);
            return memo[cur]%10007;
        }
    }

}

int main(){

    int target;
    cin >> target;
    cout << search(target) << endl;


    return 0;
}
