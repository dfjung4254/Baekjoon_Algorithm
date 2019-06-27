#include <iostream>
#include <string>
using namespace std;

int a, b, c;
string msg;

/*
    cin 으로 정수 등 다른 타입들과
    getline을 혼합해서 사용할 때 사이에 getchar();
    를 넣어줘야 버퍼가 섞이지 않는다.
*/

int main()
{
    cin.tie(0);
    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        getchar();
        int s = (a + b + c) % 25 + 1;
        s = 26 - s;
        getline(cin, msg);
        string output = "";
        int size = msg.size();
        for (int i = 0; i < size; i++)
        {
            if (msg[i] > 96 && msg[i] < 123)
            {
                int ni = (msg[i] - 97 + s) % 26 + 97;
                output += (char)ni;
            }
            else
            {
                output += msg[i];
            }
        }
        cout << output << '\n';
    }

    return 0;
}