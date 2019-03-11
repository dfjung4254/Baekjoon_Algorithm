#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Query{
    int idx, from, from_x, from_y, to, to_x, to_y, weight;
};
struct CheckPoint{
    int idx, x, y;
};
bool ret[250001] = {false, };
int n, q;
vector<CheckPoint> cp_x;
vector<CheckPoint> cp_y;
vector<Query> queries;
int checkRoot[250001] = {0, };

int findRoot(int checkNo){
    if(checkNo == checkRoot[checkNo]){
        return checkNo;
    }else{
        return checkRoot[checkNo] = findRoot(checkRoot[checkNo]);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /* 체크포인트 입력 */
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int _x, _y;
        cin >> _x >> _y;
        cp_x.push_back({i, _x, _y});
        cp_y.push_back({i, _x, _y});
        checkRoot[i] = i;
    }

    /* 쿼리 입력 */
    for(int i = 1; i <= q; i++){
        int _from, _to, _weight;
        cin >> _from >> _to >> _weight;
        queries.push_back({i, _from, cp_x[_from].x, cp_x[_from].y, _to, cp_x[_to].x, cp_x[_to].y, _weight});
    }

    /* 각각 x, y 값에 대하여 오름차순 정렬 */
    sort(cp_x.begin(), cp_x.end(), [&](CheckPoint &a, CheckPoint &b){
        return (a.x < b.x);
    });
    sort(cp_y.begin(), cp_y.end(), [&](CheckPoint &a, CheckPoint &b){
        return (a.y < b.y);
    });

    /* 각 쿼리 weight 순으로 오름차순 정렬 */
    sort(queries.begin(), queries.end(), [&](Query &a, Query &b){
        return (a.weight < a.weight);
    });
    /* 쿼리를 돌면서 각각 x, y 를 체크하며 유니온 파인드 해준다 */
    for(int i = 0; i < q; i++){

        /* 작은 weight 부터 연결 */
        int target_weight = queries[i].weight;

        int from = queries[i].from;
        int to = queries[i].to;

        /* from 과 to 의 루트 비교 */
        int rt_from = findRoot(from);
        int rt_to = findRoot(to);
        if(rt_from == rt_to){
            /* 조상이 같음 - 이미 연결되어 있음 */
            ret[queries[i].idx] = true;
            continue;
        }

        /* 조상이 다를 경우 - 직접 해당 weight 다 연결 해준다. */
        for(int idx = 0; idx < n; idx++){
            if(abs(cp_x[idx].x - cp_x[idx+1].x) <= target_weight){
                int rt_this = findRoot(cp_x[idx].idx);
                int rt_that = findRoot(cp_x[idx+1].idx);
                if(rt_this != rt_that){
                    checkRoot[rt_that] = rt_this;
                }
            }
            if(abs(cp_y[idx].y - cp_y[idx+1].y) <= target_weight){
                int rt_this = findRoot(cp_y[idx].idx);
                int rt_that = findRoot(cp_y[idx+1].idx);
                if(rt_this != rt_that){
                    checkRoot[rt_that] = rt_this;
                }
            }
        }

        /* from 과 to 의 루트 다시 비교 */
        rt_from = findRoot(from);
        rt_to = findRoot(to);
        if(rt_from == rt_to){
            /* 조상이 같음 - 이미 연결되어 있음 */
            ret[queries[i].idx] = true;
        }
    }

    for(int i = 1; i <= q; i++){
        if(ret[i]){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }

    return 0;
}