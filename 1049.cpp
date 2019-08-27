#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans1, ans2, ans3;
vector<pair<int, int>> v;

bool compSet(const pair<int, int> &pa, const pair<int, int> &pb){
    return pa.first < pb.first;
}

bool compOne(const pair<int, int> &pa, const pair<int, int> &pb){
    return pa.second < pb.second;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), compSet);
    ans3 = (n / 6 + 1) * v[0].first; 
    ans1 = (n / 6) * v[0].first;
    sort(v.begin(), v.end(), compOne);
    ans1 += (n - (n / 6) * 6) * v[0].second;
    ans2 = n * v[0].second;

    int ans = (ans1 > ans2) ? ans2 : ans1;
    ans = (ans > ans3) ? ans3 : ans;
    cout << ans << '\n';

    return 0;
}