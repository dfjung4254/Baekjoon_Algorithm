#include <iostream>
#include <vector>
using namespace std;

int t;
vector<int> ret;

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int lcm(int a, int b){
    return a*b / gcd(a,b);
}

int cal(int m, int n, int x, int y){

    int curYear = x;
    int lc = lcm(m,n);
    while(true){
        int testX = (curYear % m == 0) ? m: curYear%m;
        int testY = (curYear % n == 0) ? n: curYear%n;
        if(testX == x && testY == y){
            return curYear;
        }
        if(curYear > lc){
            return -1;
        }
        curYear += m;
    }

}

int main(){

    cin >> t;
    for(int i = 0; i < t; i++){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        ret.push_back(cal(m, n, x, y));
    }
    for(auto it=ret.begin(); it != ret.end(); it++){
        cout << *it << '\n';
    }

    return 0;
}
