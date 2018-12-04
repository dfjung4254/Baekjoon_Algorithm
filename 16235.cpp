#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int yearCount = 0;
//n : �� ������
//m : ���� ����
//k : ���
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

    //��, ����
    //�� �迭�� �����鿡�� ����� ����
    //for ������ �� �迭�� ����, ���� �ش� ���͸�
    //���̰� ������� �����Ѵ�. ����� �������ְ� �ش� ������ ���̸� +1
    //�ݸ� ���̻� ���� ����� �����ϴٸ� �ش� ������ ���� ������ ����
    //���θ� �����԰� ���ÿ� �ش� ������ ���̸� ������ �ش� �迭��
    //����� �߰����ش�.(�������� �ѹ��� ����)
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sort(trees[i][j].begin(), trees[i][j].end());
            int addBitamin = 0;
            for(auto it = trees[i][j].begin(); it != trees[i][j].end();){
                if(it->age <= currentBitamin[i][j]){
                    //����� ����. ��� �������ְ�, �ش� ������ ���̸� +1
                    currentBitamin[i][j] -= it->age;
                    it->age++;
                    it++;
                }else{
                    //����� ����. �ش� ������ �����԰� ���ÿ� �߰��� addBitamin�� ��� �߰�.
                    addBitamin += it->age / 2;
                    it = trees[i][j].erase(it);
                }
            }
            //addBitamin���� ���� ��Ÿ�θʿ� �߰�.
            currentBitamin[i][j] += addBitamin;
        }
    }

    //����
    //������ ���Ľ�Ŵ
    //for ������ �� �迭�� ����, ������ ������ ��� �����ϸ鼭
    //���� ���̰� 5�� ����̸� ������ 8ĭ�� ��������(���̴� 1)�� �߰����ش�.
    //���⼭ �迭�� ����� ���� ó�� �ʿ���.
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(auto it = trees[i][j].begin(); it != trees[i][j].end(); it++){
                if(it->age % 5 == 0){
                    //�迭�� ����� �ʴ� �������� ���� 8ĭ�� ���� �߰�
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

    //�ܿ�
    //��� �߰�
    //bitaminMatrix �� currentBitamin �� �߰����ش�.
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
