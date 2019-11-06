#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<long long> lines;
long long minLength, maxLength;

long long countCompare(long long num){

    long long count = 0;
    for(long long cur : lines){
        count += cur / num;
    }
    return count;

}

long long find(){

    while(minLength <= maxLength){
        long long midLength = (minLength + maxLength) / 2;
        long long kk = countCompare(midLength);
        if(kk >= n){
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

    cin >> k >> n;
    for(int i = 0; i < k; i++){
        long long tp;
        cin >> tp;
        lines.push_back(tp);
        maxLength += tp;
    }
    minLength = 1;
    
    cout << find() << '\n';

    return 0;
}