#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int a[100000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    vector<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i;
        while (!s.empty() && a[s.back()] > a[i])
        {
            int height = a[s.back()];
            s.pop_back();
            int width = i;
            if (!s.empty())
            {
                width = (i - s.back() - 1);
            }
            printf("size : %d - width : %d\n", width * height, width);
            if (ans < width * height)
            {
                ans = width * height;
            }
        }
        s.push_back(i);
        for(int a : s){
            printf("%d ", a);
        }
        printf("\n");
    }
    while (!s.empty())
    {
        int height = a[s.back()];
        s.pop_back();
        int width = n;
        if (!s.empty())
        {
            width = n - s.back() - 1;
        }
        printf("size : %d\n - width : ", width * height, width);
        if (ans < width * height)
        {
            ans = width * height;
        }
        for (int a : s)
        {
            printf("%d ", a);
        }
        printf("\n");
    }
    printf("%d\n", ans);
    return 0;
}