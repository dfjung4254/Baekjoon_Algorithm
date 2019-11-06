#include <iostream>
using namespace std;

int n;
int l, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int stack = 1;
    int num = 0;
    while(true){
        num += stack;
        if(n <= num){
            int sum = stack+1;
            if(stack % 2 == 0){
                //짝수
                r = 1;
                l = sum-r;
                while(num-- != n){
                    r++;
                    l--;
                }
            }else{
                //홀수
                l = 1;
                r = sum-l;
                while(num-- != n){
                    r--;
                    l++;
                }
            }
            break;
        }
        stack++;
    }
    cout << l << "/" << r << endl;

    return 0;
}