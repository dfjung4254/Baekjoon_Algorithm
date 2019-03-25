#include <iostream>
#include <stack>
using namespace std;

int n;
int height[100000];
stack<int> st;
int ans = 0;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    for (int cur = 0; cur < n; cur++){

        /* 
            현재 높이가 이전 높이보다 같거나 크면 그냥 스택에 넣는다.
            만약 현재 높이가 이전 높이보다 작으면 작업을 해주어야 한다.
            * 작업 : 스택에 들어있는 인덱스들을 빼면서 최대 넓이를 구해주어야 한다.
            * 높이 같은 경우 현재 최상단 스택의 높이를 기준으로 한다. 스택에 들어있는 값은 빼는 순서대로 높이가 작아지기 때문
            * 가로 같은 경우 최상단 스택의 이전스택의 인덱스를 기준으로 한다.
            * for 문을 벗어났을때 남아 있는 스택을 전부 사각형으로 계산해 준다.
            
            백준의 스택을 이용한 코드는 정말 영롱하다.....
            반복해서 숙지하도록 하자.. 특히 width 를 구하는 것.

            이 문제의 핵심은 스택에 높이를 오름차순으로 넣는다는 것이다. 높이의 오름차순으로 정리하다보면 
            스택을 빼면서 가능한 사각형들의 케이스를 전부 고려할 수 있다. 1 -> n 순서대로 진행을 하기 때문에
            만약 현재 넣으려는 인덱스의 높이가 이전 스택의 높이보다 낮아지는 순간 오름차순으로 정리할 수 없게되므로 스택에 있는 값들
            (현재 넣으려는 인덱스의 높이가 더 높아서 오름차순으로 스택을 넣는 것에 방해를 주는 인덱스들)을 전부 사각형화해서 계산해준 다음
            스택에 집어넣는 것이다.

            정말 감탄만 나온다...
        */

        while(!st.empty() && height[st.top()] > height[cur]){
            /* 현재 넣으려는 cur 의 높이값이 스택.top보다 작아서 오름차순이 안되는 경우 */
            /* 오름차순이 되도록 스택의 높이들을 순차적으로 빼면서 사각형의 경우의 수를 구한다. */
            /* 단 만약 도중에 현재 top 이 마지막 스택인 경우 전체 히스토그램에서 이 스택의 높이가 */
            /* 가장 작다는 말이다. 따라서 0번 인덱스부터의 길이라고 치면 된다. */
            int ht = height[st.top()];
            st.pop();
            /* wt를 정할 때 st.top() 은 현재 높이보다 작은 높이를 가진 인덱스끝까지 간다. */
            int wt = (st.empty()) ? cur : cur - st.top() - 1;
            int size = ht * wt;
            if(size > ans){
                ans = size;
            }
        }
        st.push(cur);
    }

    while(!st.empty()){
        int ht = height[st.top()];
        st.pop();
        int wt = (st.empty()) ? n : n - st.top() - 1;
        int size = ht * wt;
        if(size > ans){
            ans = size;
        }
    }

    cout << ans << '\n';

    return 0;
}