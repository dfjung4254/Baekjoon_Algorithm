#include <iostream>
#include <vector>
using namespace std;

struct Building{
    int x, h;
};

int n;
vector<Building> buildings;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        int _h;
        cin >> _h;
        buildings.push_back({i, _h});
    }

    Building point_building = buildings.front();
    int ret = 0;
    for(Building cur : buildings){

        if(cur.h > point_building.h){
            int diff = cur.x - point_building.x;
            if(diff > ret){
                ret = diff;
            }
            point_building = cur;
        }
    }

    cout << ret << '\n';

    return 0;
}