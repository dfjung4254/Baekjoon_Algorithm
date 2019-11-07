#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int yearCount = 0;
//n : 땅 사이즈
//m : 나무 개수
//k : 년수
int bitaminMatrix[101][101] = {0, };
int currentBitamin[101][101] = {0, };

class Tree{
public:
    int i;
    int j;
    int age;
    bool operator< (Tree &t) const {
        return (age < t.age);
    }
};

vector<Tree> trees[11][11];

void cycle(){
    if(yearCount == k){
        return;
    }
    yearCount++;

    //봄, 여름
    //각 배열의 나무들에게 양분을 먹임
    //for 문으로 전 배열을 돌되, 먼저 해당 벡터를
    //나이가 어린순으로 정렬한다. 양분을 제거해주고 해당 나무의 나이를 +1
    //반면 더이상 먹일 양분이 부족하다면 해당 나무와 이후 벡터의 나무
    //전부를 삭제함과 동시에 해당 나무의 나이를 나누어 해당 배열의
    //양분을 추가해준다.(여름까지 한번에 진행)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sort(trees[i][j].begin(), trees[i][j].end());
            int addBitamin = 0;
            for(auto it = trees[i][j].begin(); it != trees[i][j].end();){
                if(it->age <= currentBitamin[i][j]){
                    //양분이 있음. 양분 제거해주고, 해당 나무의 나이를 +1
                    currentBitamin[i][j] -= it->age;
                    it->age++;
                    it++;
                }else{
                    //양분이 없음. 해당 나무를 삭제함과 동시에 추가할 addBitamin에 양분 추가.
                    addBitamin += it->age / 2;
                    it = trees[i][j].erase(it);
                }
            }
            //addBitamin값을 현재 비타민맵에 추가.
            currentBitamin[i][j] += addBitamin;
        }
    }

    //가을
    //나무를 번식시킴
    //for 문으로 전 배열을 돌되, 벡터의 나무를 모두 점검하면서
    //만약 나이가 5의 배수이면 인접한 8칸에 나무벡터(나이는 1)를 추가해준다.
    //여기서 배열을 벗어나는 범위 처리 필요함.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(auto it = trees[i][j].begin(); it != trees[i][j].end(); it++){
                if(it->age % 5 == 0){
                    //배열을 벗어나지 않는 범위에서 인접 8칸에 나무 추가
                    if(i-1 >= 1 && j-1 >= 1){
                        Tree newTree;
                        newTree.i = i-1; newTree.j = j-1; newTree.age = 1;
                        trees[i-1][j-1].push_back(newTree);
                    }
                    if(i-1 >= 1){
                        Tree newTree;
                        newTree.i = i-1; newTree.j = j; newTree.age = 1;
                        trees[i-1][j].push_back(newTree);
                    }
                    if(i-1 >= 1 && j+1 <= n){
                        Tree newTree;
                        newTree.i = i-1; newTree.j = j+1; newTree.age = 1;
                        trees[i-1][j+1].push_back(newTree);
                    }
                    if(j-1 >= 1){
                        Tree newTree;
                        newTree.i = i; newTree.j = j-1; newTree.age = 1;
                        trees[i][j-1].push_back(newTree);
                    }
                    if(j+1 <= n){
                        Tree newTree;
                        newTree.i = i; newTree.j = j+1; newTree.age = 1;
                        trees[i][j+1].push_back(newTree);
                    }
                    if(i+1 <= n && j-1 >= 1){
                        Tree newTree;
                        newTree.i = i+1; newTree.j = j-1; newTree.age = 1;
                        trees[i+1][j-1].push_back(newTree);
                    }
                    if(i+1 <= n){
                        Tree newTree;
                        newTree.i = i+1; newTree.j = j; newTree.age = 1;
                        trees[i+1][j].push_back(newTree);
                    }
                    if(i+1 <= n && j+1 <= n){
                        Tree newTree;
                        newTree.i = i+1; newTree.j = j+1; newTree.age = 1;
                        trees[i+1][j+1].push_back(newTree);
                    }

                }
            }
        }
    }

    //겨울
    //양분 추가
    //bitaminMatrix 를 currentBitamin 에 추가해준다.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            currentBitamin[i][j] += bitaminMatrix[i][j];
        }
    }

    cycle();

}
int main(){

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> bitaminMatrix[i][j];
            currentBitamin[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++){
        Tree tp;
        cin >> tp.i >> tp.j >> tp.age;
        trees[tp.i][tp.j].push_back(tp);
    }
    cycle();
    int ret = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            ret += trees[i][j].size();
        }
    }
    cout << ret << endl;

    return 0;
}
