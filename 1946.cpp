#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[100000];

bool comp(const pair<int, int> &a, const pair<int, int> &b){

    return a.first < b.first;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--){

        int n;
        cin >> n;
        int max;
        int ans = 1;
        for(int i = 0; i < n; i++){
            cin >> arr[i].first;
            cin >> arr[i].second;
        }

        sort(arr, arr + n, comp);
        max = arr[0].second;

        for(int i = 1; i < n; i++){
            if(arr[i].second < max){
                ans++;
                max = arr[i].second;
            }
        }

        cout << ans << '\n';

    }

    return 0;

}