#include <iostream>
#include <math.h>
using namespace std;

int nx, ny, nr, mx, my, mr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> nx >> ny >> nr >> mx >> my >> mr;
        int dist = pow(nx-mx, 2) + pow(ny-my, 2);
        int sumr = pow(nr+mr, 2);
        int ret;
        if(nx == mx && ny == my){
            //서로 같은 점
            if(nr == mr){
                ret = -1;
            }else{
                ret = 0;
            }
        }else{
            //서로 다른 점
            if(nr*nr > pow(sqrt(dist)+mr,2) || mr*mr > pow(sqrt(dist)+nr, 2)){
                //한 원이 다른 원을 포함할때
                ret = 0;
            }else if(nr*nr == pow(sqrt(dist)+mr,2) || mr*mr == pow(sqrt(dist)+nr, 2)){
                //한 원이 다른 원을 포함하는데 겹칠때
                ret = 1;
            }else{
                if(dist > sumr){
                    //멀리 떨어져서 안만날때
                    ret = 0;
                }else if(dist == sumr){
                    //멀리 떨어져서 한점에서 만날때
                    ret = 1;
                }else{
                    //멀리 떨어져서 두 점에서 겹칠때
                    ret = 2;
                }
            }
        }
        cout << ret << '\n';
    }


    return 0;
}