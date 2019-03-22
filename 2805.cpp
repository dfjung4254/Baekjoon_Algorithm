#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<long long> lines;
long long minLength, maxLength = 0;

long long find(){

    while(minLength <= maxLength){
        long long midLength = (minLength + maxLength) / 2;
        long long sum = 0;
        for(long long num : lines){
            long long offset = (num - midLength > 0) ? num - midLength : 0;
            sum += offset;
        }
        if(sum >= m){
            minLength = midLength + 1;
        }else{
            maxLength = midLength - 1;
        }
    }
    return maxLength;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while(n--){
        long long tp;
        cin >> tp;
        lines.push_back(tp);
        if(tp > maxLength){
            maxLength = tp;
        }
    }
    minLength = 0;
    
    cout << find() << '\n';

    return 0;
}