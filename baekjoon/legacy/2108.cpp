#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 500001
#define INF 987654321
using namespace std;

// n은 홀수.
int n;
double sum = 0;
int maxret = -INF;
int minret = INF;
vector<int> v;
// 0은 양수, 1은 음수.
int nCount[2][4001];

bool comp(pair<int, int> pa, pair<int, int> pb){
    if(pa.first != pb.first){
        return pa.first > pb.first;
    }else{
        return pa.second < pb.second;
    }
}

int getAverage(){
    //산술평균, 소수점 첫째자리에서 반올림
    double d = sum / n;
    if(d >= 0){
        return round(d);
    }else{
        return -round(-d);
    }
}
int getMid(){
    //중앙값, 오름차순정렬 후 가운데값.
    sort(v.begin(), v.end());
    int idx = (n+1) / 2;
    return v.at(idx-1);
}
int getMost(){
    //최빈값. 여럭개일 경우 두번째로 작은값.

    // first : 갯수  / second : 숫자.
    vector<pair<int, int>> vc;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4001; j++){
            int num;
            if(i == 0){
                //양수
                num = j;
            }else{
                //음수
                num = -j;
            }
            vc.push_back(make_pair(nCount[i][j], num));
        }
    }
    sort(vc.begin(), vc.end(), comp);
    if(vc.at(0).first == vc.at(1).first){
        return vc.at(1).second;
    }else{
        return vc.at(0).second;
    }
}
int getDiff(){
    //최댓값과 최소값 차이
    return maxret - minret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int tp;
        cin >> tp;
        v.push_back(tp);
        sum += tp;
        if(maxret < tp){
            maxret = tp;
        }
        if(minret > tp){
            minret = tp;
        }
        if(tp >= 0){
            nCount[0][tp]++;
        }else{
            nCount[1][-tp]++;
        }
    }
    cout << getAverage() << '\n';
    cout << getMid() << '\n';
    cout << getMost() << '\n';
    cout << getDiff() << '\n';

    return 0;
}