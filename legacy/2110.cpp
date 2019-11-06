#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> house;
vector<int> diffs;
long long low, high = 0;

long long find(){

    while(low <= high){
        long long mid = (low + high) / 2;
        int count = 0;
        long long sum = 0;
        for(auto it = diffs.begin(); it != diffs.end(); it++){
            sum += *it;
            if(sum >= mid){
                sum = 0;
                count++;
            }
        }
        count++;
        if(count >= c){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return high;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    while(n--){
        int tp;
        cin >> tp;
        house.push_back(tp);
        if(tp > high){
            high = tp;
        }
    }
    low = 1;
    sort(house.begin(), house.end());
    for(auto it = house.begin(); it != house.end() - 1; it++){
        int diff = *(it+1) - *it;
        diffs.push_back(diff);
    }

    cout << find() << '\n';

    return 0;
}