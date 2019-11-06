#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
set<string> s;
set<string> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tp;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> tp;
        s.insert(tp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> tp;
        if(s.find(tp) != s.end())
        {
            ans.insert(tp);
        }
    }
    cout << ans.size() << '\n';
    for(string str : ans)
    {
        cout << str << '\n';
    }

    return 0;
}