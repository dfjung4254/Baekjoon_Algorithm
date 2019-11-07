#include <iostream>
#include <cmath>
using namespace std;

int tx, ty, dx, dy;

struct Circle{
    int x;
    int y;
    int r;
};

bool isInCircle(Circle circle, int px, int py){

    return pow(px-circle.x, 2)+pow(py-circle.y, 2) < pow(circle.r,2);

}

bool isValid(Circle circle, int x1, int y1, int x2, int y2){

    bool flag1 = isInCircle(circle, x1, y1);
    bool flag2 = isInCircle(circle, x2, y2);

    return (flag1 != flag2);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int ret = 0;
        cin >> tx >> ty >> dx >> dy;
        int p_size;
        cin >> p_size;
        while(p_size--){
            int x, y, r;
            cin >> x >> y >> r;
            if(isValid({x,y,r}, tx, ty, dx, dy)){
                ret++;
            }
        }
        cout << ret << '\n';
    }

    return 0;
}