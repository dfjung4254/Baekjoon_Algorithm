#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack{
private:
    int *stack;
    int size;
    int pos;
    vector<int> v;
public:
    Stack(int _size = 0){
        size = _size;
        stack = new int[size];
        pos = 0;
    }
    ~Stack(){
        delete[] stack;
    }
    void push(int x){
        if(pos == size){
            return;
        }
        stack[pos] = x;
        pos++;
    }
    void pop(){
        if(pos == 0){
            v.push_back(-1);
        }else{
            pos--;
            v.push_back(stack[pos]);
        }
    }
    void getSize(){
        v.push_back(pos);
    }
    void isEmpty(){
        if(pos == 0){
            v.push_back(1);
        }else{
            v.push_back(0);
        }
    }
    void top(){
        if(pos == 0){
            v.push_back(-1);
        }else{
            v.push_back(stack[pos-1]);
        }
    }
    vector<int> getV(){
        return v;
    }
};

int main(){

    Stack *myStack;
    int size;
    cin >> size;
    myStack = new Stack(size);
    for(int i = 0; i < size; i++){

        string a;
        cin >> a;
        if(a.compare("push") == 0){
            int x;
            cin >> x;
            myStack->push(x);
        }else if(a.compare("pop") == 0){
            myStack->pop();
        }else if(a.compare("size") == 0){
            myStack->getSize();
        }else if(a.compare("empty") == 0){
            myStack->isEmpty();
        }else if(a.compare("top") == 0){
            myStack->top();
        }

    }
    for(int i = 0; i < myStack->getV().size(); i++){
        cout << myStack->getV()[i] << endl;
    }
    delete myStack;

    return 0;
}
