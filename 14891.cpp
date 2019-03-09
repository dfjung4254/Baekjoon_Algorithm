#include <iostream>
#include <cmath>
using namespace std;

class Gear
{
  public:
    bool teeth[8];
    void rotate(bool direction);
};

void Gear::rotate(bool direction)
{

    int offset = (direction) ? 7 : 1;
    bool buff[8];
    for (int i = 0; i < 8; i++)
    {
        int idx = (i + offset) % 8;
        buff[i] = teeth[idx];
    }
    for (int i = 0; i < 8; i++)
    {
        teeth[i] = buff[i];
    }
}

int n;
Gear gears[4];

void operateGears(int gearNo, bool direction, bool rotated[])
{

    /* 
    
        현재 기어를 돌리기 전에 양 옆의 기어를 확인하고
        현재 기어를 회전 한 후 양 옆의 기어를 operateGears 해준다
    
    */
    bool g_right = false;
    bool g_left = false;
    if (gearNo + 1 < 4 && gears[gearNo + 1].teeth[6] != gears[gearNo].teeth[2] && !rotated[gearNo + 1])
    {
        g_right = true;
    }
    if (gearNo - 1 >= 0 && gears[gearNo - 1].teeth[2] != gears[gearNo].teeth[6] && !rotated[gearNo - 1])
    {
        g_left = true;
    }

    gears[gearNo].rotate(direction);
    rotated[gearNo] = true;

    if (g_right)
    {
        operateGears(gearNo + 1, !direction, rotated);
    }
    if (g_left)
    {
        operateGears(gearNo - 1, !direction, rotated);
    }
}

int countGearScore()
{
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        if (gears[i].teeth[0])
        {
            ret += pow(2, i);
        }
    }
    return ret;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char input;
            cin >> input;
            bool tp = (input == '1') ? true:false;
            gears[i].teeth[j] = tp;
        }
    }
    cin >> n;
    while (n--)
    {
        int cmd_gearNo;
        int cmd_direction;
        bool rotated_gear[4] = {
            false,
        };
        cin >> cmd_gearNo >> cmd_direction;
        bool dir = (cmd_direction == 1) ? true : false;
        operateGears(cmd_gearNo-1, dir, rotated_gear);
    }

    cout << countGearScore() << '\n';

    return 0;
}