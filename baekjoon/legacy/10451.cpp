#include <iostream>
using namespace std;

int matrix[1001];
bool visited[1001];

int ans;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++){
            cin >> matrix[i];
            visited[i] = false;
        }

        ans = 0;

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                ans++;
                int next = matrix[i];
                visited[i] = true;
                while(!visited[next]){
                    visited[next] = true;
                    next = matrix[next];
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}