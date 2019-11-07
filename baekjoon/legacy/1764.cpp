#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<string> people;
vector<string> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string tp;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tp;
        people.push_back(tp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tp;
        people.push_back(tp);
    }
    sort(people.begin(), people.end());
    int size = people.size();
    string before = people[0];
    for(int i = 1; i < size; i++)
    {
        if(before.compare(people[i]) == 0)
        {
            ans.push_back(before);
        }
        before = people[i];
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(string str : ans)
    {
        cout << str << '\n';
    }

    return 0;
}