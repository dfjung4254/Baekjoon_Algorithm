#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
    int x, y;
    bool operator<(const Point &p){
        if(x == p.x){
            return (y < p.y);
        }else{
            return (x < p.x);
        }
    }
};
int n;
vector<Point> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        int _x, _y;
        cin >> _x >> _y;
        v.push_back({_x, _y});
    }
    sort(v.begin(), v.end());
    for(Point p : v)
    {
        cout << p.x << " " << p.y << '\n';
    }

    return 0;
}