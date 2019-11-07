#include <iostream>
#include <vector>
using namespace std;

vector<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        q.clear();
        int size, idx;
        cin >> size >> idx;
        for(int i = 0; i < size; i++){
            int tp;
            cin >> tp;
            q.push_back(tp);
        }
        int cnt = 0;
        while(true){
            int cur = q.front();
            q.erase(q.begin());
            bool isPop = true;
            for(int num : q){
                if(num > cur){
                    isPop = false;
                    break;
                }
            }
            if(isPop){
                // 인쇄함
                if(idx == 0){
                    break;
                }else{
                    idx--;
                    cnt++;
                }
            }else{
                // 인쇄안하고 뒤로보냄
                q.push_back(cur);
                if(idx == 0){
                    idx = q.size()-1;
                }else{
                    idx--;
                }
            }
        }
        cout << cnt+1 << '\n';
    }
    
    return 0;
}