#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while(n--){
        int tp;
        cin >> tp;
        v.push_back(tp);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int sum = 0;
    for(int num : v){
        sum += num;        
        ans = ans + sum;
    }
    cout << ans << '\n';

    return 0;
}