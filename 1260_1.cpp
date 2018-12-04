#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> dfsResult;

class Point{
    int v;
    vector<int> next;
public:
    Point(int v = 0):v(v){}
    void setLoc(int x){
        next.push_back(x);
    }
    void setV(int x){
        v = x;
    }
    vector<int> getNext(){
        return next;
    }
};

void dfs(Point points[], int v, int targetSize, vector<int> stack){

    stack.push_back(v);

    if(targetSize == stack.size()){
        //find location
        dfsResult.push_back(stack);
        return;
    }

    Point current;
    current = points[v-1];
    int nextV = -1;
    for(int i = 0; i < current.getNext().size(); i++){
        bool flag = true;
        for(int j = 0; j < stack.size(); j++){
            if(current.getNext()[i] == stack[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            dfs(points, current.getNext()[i], targetSize, stack);
        }
    }

}

void bfs(Point points[], int v, int targetSize, queue<int> queue){

    bool check[targetSize];
    cout << v << " ";
    for(int i = 0; i < targetSize; i++){
        check[i] = false;
    }
    queue.push(v);
    check[v-1] = true;

    Point current = points[v-1];

    while(!queue.empty()){
        int pop = queue.front();
        queue.pop();

        for(int i = 0; i < points[pop-1].getNext().size(); i++){
            if(check[i] == false){
                cout <<
            }
        }

    }


}

int main(){

    int n, m, v;
    cin >> n >> m >> v;
    Point point[n];
    for(int i = 0; i < n; i++){
        point[i].setV(i+1);
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        point[a-1].setLoc(b);
        point[b-1].setLoc(a);
    }
    vector<int> mystack;
    dfs(point, v, n, mystack);
    for(int i = 0; i < dfsResult.at(0).size(); i++){
        cout << dfsResult.at(0).at(i) << " ";
    }
    cout << endl;

    return 0;
}
