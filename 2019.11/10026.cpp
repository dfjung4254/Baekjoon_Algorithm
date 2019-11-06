#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<vector<char>> origin;
    cin >> n;

    for(int i = 0; i < n; i++){
        vector<char> vv;
        origin.push_back(vv);
        for(int j = 0; j < n; j++){
            char ch;
            cin >> ch;
            origin.back().push_back(ch);
        }
    }

    



    return 0;
}