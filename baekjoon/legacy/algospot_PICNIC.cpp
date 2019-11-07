#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

void goDp(int curNum, int matrix[], int idx){

    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int pa, pb;
            cin >> pa >> pb;
            if(pb > pa){
                int tp = pa;
                pa = pb;
                pb = tp;
            }
            v.push_back(make_pair(pb, pa));
        }

    }

    return 0;
}