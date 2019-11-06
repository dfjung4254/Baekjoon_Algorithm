#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;
vector<int> targets;
int low, high, mid;

int upperBound(int target){

    low = 0;
    high = nums.size() - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(nums[mid] <= target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    int ret = (nums[low-1] == target) ? low-1:-1;
    return ret;
}

int lowerBound(int target){
    
    low = 0;
    high = nums.size() - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(nums[mid] >= target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    int ret = (nums[high+1] == target) ? high + 1:-1;
    return ret;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    while(n--){
        int tp;
        cin >> tp;
        nums.push_back(tp);
    }
    cin >> m;
    while(m--){
        int tp;
        cin >> tp;
        targets.push_back(tp);
    }
    sort(nums.begin(), nums.end());
    for(int targ : targets){

        int _low = lowerBound(targ);
        int _high = upperBound(targ);
        int ret = (_low == -1) ? 0:_high-_low+1;
        cout << ret << " ";
    }

    return 0;
}