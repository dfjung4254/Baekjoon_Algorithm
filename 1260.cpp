#include <iostream>
#include <vector>
using namespace std;

class V{
public:
    int v;
    vector<int> locate;
    V(int v = 0):v(v) {}
};

void dfs(V point[], int init, vector<int> stack, int size){
    stack.push_back(init);
    // cout << "������Ȳ : ";
    // for(auto it = stack.begin(); it != stack.end(); it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    if(stack.size() == size){
        //������ ������, ��θ� ã��
//        cout << "���ã�� : ";
        for(int i = 0; i < stack.size(); i++){
            cout << stack[i] << " ";
        }
        cout << endl;
        return;
    }

    int next = -1;
    for(auto it = point[init-1].locate.begin(); it != point[init-1].locate.end(); it++){
        bool findPass = true;
        for(auto it2 = stack.begin(); it2 != stack.end(); it2++){
            if(*it == *it2){
                findPass = false;
                break;
            }
        }
        if(findPass){
            next = *it;
            //������� Ž��
//            cout << next << "�� ����" << endl;
            dfs(point, next, stack, size);
        }
    }
    if(next == -1){
        //������� ���� ������ �÷�����.
//        cout << "����" << endl;
        return;
    }

}


int main(){

    int n, m, v;
    cin >> n >> m >> v;
    V *point;
    point = new V[n];
    for(int i = 0; i < n; i++){
        point[i].v = i+1;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        point[a-1].locate.push_back(b);
        point[b-1].locate.push_back(a);
    }
    vector<int> myStack;
    dfs(point, v, myStack, n);

    // ���
    // for(int i = 0; i < n; i++){
    //     cout << point[i].v << " : ";
    //     for(auto it = point[i].locate.begin(); it != point[i].locate.end(); it++){
    //         cout << *it << " ";
    //     }
    //     cout << '\n';
    // }

    delete[] point;

    return 0;
}
