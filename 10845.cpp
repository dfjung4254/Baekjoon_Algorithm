#include <iostream>
#include <vector>
using namespace std;

class Queue{

private:
    int queue[10000];
    int front;
    int rear;
public:
    Queue():front(0), rear(0){}
    void push(int x){
        queue[++rear] = x;
    }
    bool isEmpty(){
        return front == rear;
    }
    int getSize(){
        return rear-front;
    }
    int pop(){
        if(isEmpty()){
            return -1;
        }else{
            return queue[++front];
        }
    }
    int getFront(){
        if(isEmpty()){
            return -1;
        }else{
            return queue[front+1];
        }
    }
    int getBack(){
        if(isEmpty()){
            return -1;
        }else{
            return queue[rear];
        }
    }

};

int main(){

    int n;
    cin >> n;
    vector<int> ret;
    Queue q;
    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        if(command.compare("push") == 0){
            int x;
            cin >> x;
            q.push(x);
        }else if(command.compare("pop") == 0){
            ret.push_back(q.pop());
        }else if(command.compare("size") == 0){
            ret.push_back(q.getSize());
        }else if(command.compare("empty") == 0){
            ret.push_back(q.isEmpty());
        }else if(command.compare("front") == 0){
            ret.push_back(q.getFront());
        }else if(command.compare("back") == 0){
            ret.push_back(q.getBack());
        }
    }
    for(auto it = ret.begin(); it != ret.end(); it++){
        cout << *it << '\n';
    }

    return 0;
}
