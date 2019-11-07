#include <iostream>
#include <vector>
using namespace std;

long long n;
vector<long long> v;

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(long long i = 1; i*i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
        }
    }

    long long a = v.back();
    long long b = n / a;
    long long ret = b - a;

    cout << ret << '\n';

    return 0; 
}