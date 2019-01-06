#include <iostream>
#include <set>
using namespace std;

int nums[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int tp;
        cin >> tp;
        nums[tp]++;
    }

    for(int tp = 1; tp <= 10000; tp++){
        if(nums[tp] != 0){
            for(int i = 0; i < nums[tp]; i++){
                cout << tp << '\n';
            }
        }
    }

    return 0;
}
