#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
struct Pokemon{
    int idx;
    string name;
};
vector<Pokemon> dex;
vector<Pokemon> dex_sorted;

int find(string s){

    int low = 1;
    int high = dex.size() - 1;
    int mid = 0;
    while(low <= high){
        mid = (low + high) / 2;
        string tp = dex_sorted[mid].name;
        if(tp.compare(s) == 0){
            return dex_sorted[mid].idx;
        }else if (tp.compare(s) < 0){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dex.push_back({0, "null"});
    dex_sorted.push_back({0, "null"});
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        dex.push_back({i, s});
        dex_sorted.push_back({i, s});
    }
    sort(dex_sorted.begin()+1, dex_sorted.end(), [](Pokemon &a, Pokemon &b)->bool{
        return (a.name.compare(b.name) < 0);
    });
    while(m--){
        string s;
        cin >> s;
        /* 문자인지 숫자인지 판별 */
        int p = atoi(s.c_str());
        if(p == 0){
            /* 문자 */
            cout << find(s) << '\n';
        }else{
            /* 숫자 */
            cout << dex[p].name << '\n';
        }
    }

    return 0;
}