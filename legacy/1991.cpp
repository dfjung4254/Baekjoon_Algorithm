#include <iostream>
using namespace std;

class Node{
private:
    int idx;
    int leftIdx, rightIdx;
public:
    Node(int a  = -1) : idx(a) {
        leftIdx = -1;
        rightIdx = -1;
    }
    void setLchild(int lc);
    void setRchild(int rc);
    int getLchild();
    int getRchild();
    int getIdx();
};

void Node::setLchild(int lc){
    leftIdx = lc;
}
void Node::setRchild(int rc){
    rightIdx = rc;
}
int Node::getLchild(){
    return leftIdx;
}
int Node::getRchild(){
    return rightIdx;
}
int Node::getIdx(){
    return idx;
}

int n;
Node nodes[26];
const char nodeCh[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z'
};

void setNodes(){
    for(int i = 0; i < 26; i++){
        nodes[i] = i;
    }
}

int searchIndex(char ch){
    int ret = -1;
    for(int i = 0; i < 26; i++){
        if(nodeCh[i] == ch){
            ret = i;
            break;
        }
    }
    return ret;
}

void preCycle(int idx){
    if(idx == -1){
        return;
    }
    cout << nodeCh[idx];
    preCycle(nodes[idx].getLchild());
    preCycle(nodes[idx].getRchild());
}

void midCycle(int idx){
    if(idx == -1){
        return;
    }
    midCycle(nodes[idx].getLchild());
    cout << nodeCh[idx];
    midCycle(nodes[idx].getRchild());
}

void postCycle(int idx){
    if(idx == -1){
        return;
    }
    postCycle(nodes[idx].getLchild());
    postCycle(nodes[idx].getRchild());
    cout << nodeCh[idx];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    setNodes();
    cin >> n;
    while(n--){
        char rt, lc, rc;
        cin >> rt >> lc >> rc;
        int rtidx = searchIndex(rt);
        int lcidx = searchIndex(lc);
        int rcidx = searchIndex(rc);
        if(lcidx != -1){
            nodes[rtidx].setLchild(lcidx);
        }
        if(rcidx != -1){
            nodes[rtidx].setRchild(rcidx);
        }
    }
    //순회
    preCycle(0);
    cout << '\n';
    midCycle(0);
    cout << '\n';
    postCycle(0);
    

    return 0;
}