#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct edge{
    int x, y;
    bool operator < (const edge &e){
        if(y == e.y){
            return x < e.x;
        }else{
            return y < e.y;
        }
    }
};
vector<edge> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--){
        int tx, ty;
        cin >> tx >> ty;
        v.push_back({tx, ty});
    }
    sort(v.begin(), v.end());
    int ret = 0;
    int befc = 0;
    for(edge e : v){
        if(e.x >= befc){
            ret++;
            befc = e.y;
        }
    }
    cout << ret << '\n';

    return 0;
}