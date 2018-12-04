#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> retStack;

class Point{
public:
    vector<int> connectLine;
};

void dfs(Point points[], int v, int targetSize, vector<int> stack){
    stack.push_back(v);
    if(stack.size() == targetSize){
        retStack.push_back(stack);
        return;
    }
    for(int i = 0; i < points[v-1].connectLine.size(); i++){
        bool flag = true;
        for(int j = 0; j < stack.size(); j++){
            if(points[v-1].connectLine[i] == stack[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            dfs(points, points[v-1].connectLine[i], targetSize, stack);
        }
    }
}

void bfs(Point points[], int v, int targetSize, vector<int> stack){
    queue<int> current;
    current.push(v);
    stack.push_back(v);
    while(!current.empty()){
        int now = current.front();
        current.pop();
        for(auto it = points[now-1].connectLine.begin(); it != points[now-1].connectLine.end(); it++){
            bool flag = true;
            for(int i = 0; i < stack.size(); i++){
                if(*it == stack[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                current.push(*it);
                stack.push_back(*it);
            }
        }
    }
    for(int i = 0; i < stack.size(); i++){
        cout << stack[i] << " ";
    }
    cout << '\n';
}

int main(){

    int n, m, v;
    cin >> n >> m >> v;
    Point points[n];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        points[a-1].connectLine.push_back(b);
        points[b-1].connectLine.push_back(a);
    }
    vector<int> myStack;
    dfs(points, v, n, myStack);
    for(int i= 0; i < n; i++){
        cout << retStack[0][i] << " ";
    }
    cout << '\n';
    myStack.clear();
    bfs(points, v, n, myStack);

    return 0;
}
