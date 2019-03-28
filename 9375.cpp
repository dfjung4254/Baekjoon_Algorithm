#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<string> v;
        vector<int> ct;
        while(n--){
            string input1, input2;
            cin >> input1 >> input2;
            bool isSame = false;
            int sz = v.size();
            for (int i = 0; i < sz; i++)
            {
                if(v[i].compare(input2) == 0){
                    isSame = true;
                    ct[i]++;
                }
            }
            if(!isSame){
                v.push_back(input2);
                ct.push_back(1);
            }
        }
        int ret = 1;
        for(int num : ct){
            ret *= (num + 1);
        }
        cout << ret - 1 << '\n';
    }

    return 0;
}