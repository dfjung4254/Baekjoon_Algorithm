#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;
vector<int> ans;

bool find(int target){

    int low = 0;
    int high = nums.size()-1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target){
            return true;
        }else if(nums[mid] > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return false;
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
        ans.push_back(tp);
    }
    sort(nums.begin(), nums.end());
    
    for(int num : ans){
        if(find(num)){
            cout << "1" << '\n';
        }else{
            cout << "0" << '\n';
        }
    }

    return 0;
}