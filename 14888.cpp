#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int maxRet = -1234567890;
int minRet = 1234567890;
vector<int> v;
vector<int> operators;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /* 입력 */
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tp;
        cin >> tp;
        v.push_back(tp);
    }
    for (int i = 0; i < 4; i++)
    {
        int count;
        cin >> count;
        while (count--)
        {
            operators.push_back(i);
        }
    }

    do
    {

        int tpRet = v.front();
        for(int i = 1; i < n; i++){
            switch (operators.at(i-1))
            {
                case 0:
                    /* plus */
                    tpRet += v.at(i);
                    break;
                case 1:
                    tpRet -= v.at(i);
                    break;
                case 2:
                    tpRet *= v.at(i);
                    break;
                case 3:
                    tpRet /= v.at(i);
                    break;
                default:
                    break;
            }
        }

        if(tpRet > maxRet){
            maxRet = tpRet;
        }

        if(tpRet < minRet){
            minRet = tpRet;
        }

    } while (next_permutation(operators.begin(), operators.end()));

    cout << maxRet << '\n' << minRet << '\n';

    return 0;
}