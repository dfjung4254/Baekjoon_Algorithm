#include <iostream>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    
    while(tc--){
        int l, n;
        cin >> l >> n;
        int tn = n;
        int mid = l / 2;
        int min = 1000000, max = 1000000;
        int vMin, vMax, ans1, ans2;
        while(tn--){
            int tp;
            cin >> tp;
            if(abs(tp - mid) < min){
                min = abs(tp - mid);
                vMin = tp;
            }
            if(tp <= mid && tp < max){
                max = tp;
                vMax = tp;
            }
            if(tp > mid && l - tp < max){
                max = l - tp;
                vMax = tp;
            }
        }
        if(vMin <= mid){
            ans1 = vMin;
        }else{
            ans1 = l - vMin;
        }
        if(vMax <= mid){
            ans2 = l - vMax;
        }else{
            ans2 = vMax;
        }
        cout << ans1 << " " << ans2 << '\n';
    }

    return 0;
}