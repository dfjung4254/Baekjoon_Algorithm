#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, minCount = 0;
        int cSpeed = 0;
        cin >> n >> m;
        int dist = m - n;
        while (dist)
        {
            int maxDist = 0;
            int ts = cSpeed + 1;
            if(ts%2 == 0){
                maxDist = (ts+1)*(ts/2);
            }else{
                maxDist = (ts+1)*(ts/2) + (ts+1)/2;
            }
            if (dist >= maxDist)
            {
                dist -= ++cSpeed;
                minCount++;
            }
            else
            {
                maxDist -= (cSpeed+1);
                if(dist >= maxDist){
                    dist -= cSpeed;
                    minCount++;
                }else{
                    dist -= --cSpeed;
                    minCount++;
                }
            }
        }
        cout << minCount << '\n';
    }
    return 0;
}