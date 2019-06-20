#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(true)
    {
        string str;
        getline(cin, str);
        if(str.compare("END") == 0)
        {
            break;
        }

        int size = str.size();
        for(int i = size-1; i >= 0; i--)
        {
            cout << str[i];
        }
        cout << '\n';

    }

    return 0;
}