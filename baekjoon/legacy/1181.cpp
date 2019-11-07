#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> v;
bool comp(const string &a, const string &b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }else{
        return a.compare(b) < 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--){
        string tp;
        cin >> tp;
        v.push_back(tp);
    }
    sort(v.begin(), v.end(), comp);
    string backup = "";
    for(string t : v){
        if(backup.compare(t) == 0){
            continue;
        }
        cout << t << '\n';
        backup = t;
    }

    return 0;
}