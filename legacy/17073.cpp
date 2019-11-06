#include <iostream>
#include <vector>
using namespace std;

int n, w;
struct Tree{
    int weight = 0;
    vector<int> connectIdx;
};
Tree trees[500001];
double ans = 0;
int cnt = 0;

void search(int parentIdx, int curIdx){
    //cout << parentIdx << " : enter " << trees[parentIdx].connectIdx.size() << '\n';
    int offset = 0;

    if(trees[curIdx].connectIdx.size() == 1){
        // 부모 노드 말고 없는 경우
        //cout << curIdx << " / " << trees[curIdx].weight << '\n';
        cnt++;
        ans += trees[curIdx].weight;
        return;
    }

    int size = trees[curIdx].connectIdx.size() - 1;

    for(int nextIdx : trees[curIdx].connectIdx){
        if(nextIdx != parentIdx){
            // 자식 노드
            offset = trees[curIdx].weight / size;
            trees[curIdx].weight -= offset;
            size--;
            trees[nextIdx].weight = offset;
            search(curIdx, nextIdx);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        trees[a].connectIdx.push_back(b);
        trees[b].connectIdx.push_back(a);
    }
    trees[1].connectIdx.push_back(1);
    trees[1].weight = w;

    search(1, 1);

    double answer = (double)w / cnt;

    cout << answer << '\n';

    return 0;
}