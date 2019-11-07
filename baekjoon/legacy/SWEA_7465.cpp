#include <iostream>
using namespace std;

int root[101];

int findRoot(int n){
    if(root[n] == n){
        return n;
    }else{
        return root[n] = findRoot(root[n]);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    int tcase = 1;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        int ans = n;
        for (int i = 1; i <= n; i++)
        {
            root[i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            int ra = findRoot(a);
            int rb = findRoot(b);
            if(ra != rb){
                root[rb] = ra;
                ans--;
            }
        }
        cout << "#" << tcase++ << " " << ans << '\n';
    }

    return 0;
}