#include <iostream>
#include <string.h>
#define MAX 1001
using namespace std;

int ret = 0;
bool nums[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(nums, true, sizeof(nums));
    nums[1] = false;
    for(int i = 2; i < MAX; i++){
        if(nums[i]){
            for(int j = i*2; j < MAX; j += i){
                nums[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    while(n--){
        int tp;
        cin >> tp;
        if(nums[tp]){
            ret++;
        }
    }
    cout << ret << '\n';

    return 0;
}