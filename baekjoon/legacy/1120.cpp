#include <iostream>
#include <string>
using namespace std;

string a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;

    int aSize = a.size();
    int diff = b.size() - aSize;
    int ans = 987654321;

    for (int i = 0; i <= diff; i++){
        int tpAns = 0;
        for (int j = 0; j < aSize; j++){
            int idx = i + j;
            if(a[j] != b[idx]){
                tpAns++;
            }
        }
        if(tpAns < ans){
            ans = tpAns;
        }
    }

    cout << ans << '\n';

    return 0;
}