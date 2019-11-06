#include <iostream>
#include <string>
using namespace std;

struct SCORE
{
    string name;
    double score;
};

SCORE pa[13] = {
    {"A+", 4.3},
    {"A0", 4.0},
    {"A-", 3.7},
    {"B+", 3.3},
    {"B0", 3.0},
    {"B-", 2.7},
    {"C+", 2.3},
    {"C0", 2.0},
    {"C-", 1.7},
    {"D+", 1.3},
    {"D0", 1.0},
    {"D-", 0.7},
    {"F", 0.0},
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >> input;
    cout << fixed;
    cout.precision(1);
    for(SCORE sc : pa)
    {
        if(sc.name.compare(input) == 0)
        {
            cout << sc.score << '\n';
            break;
        }
    }

    return 0;
}