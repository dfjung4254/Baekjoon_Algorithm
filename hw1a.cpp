/*
*   Algorithm Programming Assignment #1
*   Professor : 정균락 교수님
*   class : 알고리즘 분석 - 1
*   Student No : B354025
*   Name : 정근화
*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class TreeNode
{
  public:
    int idx, leftIdx, rightIdx, weight;
    TreeNode() {}
    void setTree(int i, int l, int r, int w)
    {
        idx = i;
        leftIdx = l;
        rightIdx = r;
        weight = w;
    }
};
TreeNode treeNode[1001];
int retCount = 0;

void setWeight(int idx)
{

    TreeNode curNode = treeNode[idx];
    int lw = treeNode[curNode.leftIdx].weight;
    int rw = treeNode[curNode.rightIdx].weight;
    treeNode[idx].weight = lw + rw;
}

int searchWeight(int idx)
{

    TreeNode curNode = treeNode[idx];

    if (idx == -1)
    {
        return 0;
    }

    if (curNode.leftIdx == -1 && curNode.rightIdx == -1)
    {
        /* 최하단 노드 */
        return treeNode[idx].weight = 1;
    }

    int lc = searchWeight(curNode.leftIdx);
    int rc = searchWeight(curNode.rightIdx);

    if (lc < rc)
    {
        retCount++;
    }

    return treeNode[idx].weight = lc + rc + 1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream input;
    input.open("input.txt");

    if (input.is_open())
    {
        int tc;
        input >> tc;
        while (tc--)
        {
            int n;
            retCount = 0;
            input >> n;
            while (n--)
            {
                int t, a, b;
                input >> t >> a >> b;
                treeNode[t].setTree(t, a, b, 0);
            }
            searchWeight(1);
            cout << retCount << '\n';
        }
    }

    return 0;
}