#include <iostream>
#include <queue>
using namespace std;

int minCount = 100000;
int visited[100001];

void find(int x, int y, queue<int> queue){

    visited[x] = 0;
    queue.push(x);
    while(!queue.empty()){
        int v = queue.front();
        queue.pop();
        if(v == y){
            //find
            cout << visited[v] << endl;
            return;
        }else{
            if(v+1 <= 100000 && visited[v+1] == false){
                queue.push(v+1);
                visited[v+1] = visited[v]+1;
            }
            if( v-1 >= 0 && visited[v-1] == false){
                queue.push(v-1);
                visited[v-1] = visited[v]+1;
            }
            if(v*2 <= 100000 && v!=0 && visited[v*2] == false){
                queue.push(v*2);
                visited[v*2] = visited[v]+1;
            }
        }


    }

}

int main(){

    int x, y;
    cin >> x >> y;
    queue<int> myQueue;
    find(x, y, myQueue);
    return 0;
}
