#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*

    조낸 어려움 꼭 다시 풀어보기 바람.
    삼성SW 기출임 이정도는 빠르게 풀어야 할 실력이 되어야한다.

*/

int n, m;
int ret;
vector<pair<int, int>> house;
vector<pair<int, int>> chickens;
bool visited[13];

int getDist(int i, int j, int pi, int pj){
    int reti = (i-pi > 0) ? i-pi:pi-i;
    int retj = (j-pj > 0) ? j-pj:pj-j;
    return reti+retj;
}

int checkDistance(pair<int,int> chi[], int size){
    int ret = 0;
    for(auto it = house.begin(); it != house.end(); it++){
        int dist = 0;
        for(int i = 0; i < size; i++){
            int tmpDist = getDist(it->first,it->second,chi[i].first,chi[i].second);
            if(dist > tmpDist || dist == 0){
                dist = tmpDist;
            }
        }
        ret += dist;
    }
    return ret;
}

void comb(int arr[], int index, int size, int r, int target){

    if(r == 0){
        pair<int, int> chi[m];
        for(int i = 0; i < m; i++){
            chi[i] = chickens[arr[i]];
        }
        int a = checkDistance(chi, m);
        if(ret > a || ret == 0){
            ret = a;
        }
        return;
    }else if(target == size){
        return;
    }else{
        arr[index] = target;
        comb(arr, index+1, size, r-1, target+1);
        comb(arr, index, size, r, target+1);
    }

}

int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int input;
            cin >> input;
            if(input == 1){
                house.push_back(make_pair(i,j));
            }else if(input == 2){
                chickens.push_back(make_pair(i,j));
            }
        }
    }
    int arr[m];
    comb(arr, 0, chickens.size(), m, 0);
    cout << ret << endl;
    return 0;
}
