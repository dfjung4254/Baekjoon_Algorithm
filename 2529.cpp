#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> rCount;
vector<int> ret;
bool visited[10];
int lCount = 0;

vector<int> mlCount;
vector<int> mRet;
bool mVisited[10];
int mrCount = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int count = 0;
    int mCount = 0;
    for(int i = 1; i <= n; i++){
        char ch;
        cin >> ch;
        if(ch == '<'){
            count++;
            mrCount++;
            mlCount.push_back(mCount);
            mCount = 0;
        }else{
            lCount++;
            rCount.push_back(count);
            count = 0;
            mCount++;
        }
    }
    rCount.push_back(count);
    mlCount.push_back(mCount);
    // for(int c : rCount){
    //     cout << c << " > ";
    // }
    for(int c : rCount){
        int t = c+1;
        int count = 0;
        stack<int> st;
        for(int i = 9; i >= 0; i--){
            if(!visited[i]){
                visited[i] = true;
                st.push(i);
                count++;
            }
            if(count == t) break;
        }
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
    }
    for(int c : mlCount){
        int t = c+1;
        int count = 0;
        stack<int> st;
        for(int i = 0; i <= 9; i++){
            if(!mVisited[i]){
                mVisited[i] = true;
                st.push(i);
                count++;
            }
            if(count == t) break;
        }
        while(!st.empty()){
            mRet.push_back(st.top());
            st.pop();
        }
    }
    for(int r : ret){
        cout << r;
    }
    cout << '\n';
    for(int r : mRet){
        cout << r;
    }
    return 0;
}