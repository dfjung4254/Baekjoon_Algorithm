#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int matrix[101][101] = {0, };

void makeCurv(vector<pair<int,int>> v, int targetG, int curG, int direction){

    if(targetG+1 == curG){
        //matrix 에 v 좌표를 토대로 그려준다.
        for(auto it = v.begin(); it != v.end(); it++){
            int x = (*it).first;
            int y = (*it).second;
            if(x >= 0 && y >= 0){
                matrix[y][x] = 1;
            }
        }
        return;
    }
    int x = v.back().first;
    int y = v.back().second;
    if(curG == 0){
        if(direction == 0){
            v.push_back(make_pair(x+1,y));
        }else if(direction == 1){
            v.push_back(make_pair(x,y-1));
        }else if(direction == 2){
            v.push_back(make_pair(x-1,y));
        }else{
            v.push_back(make_pair(x,y+1));
        }
    }else{
        int size = v.size()-2;
        for(int i = size; i >= 0; i--){
            if(true){
                int nx = (v.at(i)).first;
                int ny = (v.at(i)).second;
                nx = nx-x;
                ny = ny-y;
                int tp = nx;
                nx = -ny;
                ny = tp;
                nx = nx+x;
                ny = ny+y;
                v.push_back(make_pair(nx,ny));
            }
        }
    }
    makeCurv(v, targetG, curG+1, direction);
}

int main(){

    cin >> n;
    int testCase[n];
    for(int i = 0; i < n; i++){
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<pair<int,int>> v;
        v.push_back(make_pair(x,y));
        makeCurv(v, g, 0, d);
    }
    int count = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(matrix[i][j] != 0 && matrix[i][j+1] != 0
            && matrix[i+1][j] != 0 && matrix[i+1][j+1] != 0){
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}
