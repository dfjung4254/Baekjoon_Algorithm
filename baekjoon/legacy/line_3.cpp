#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct MyTable{
    int idx;
    vector<string> val;
};

int n_t1, n_t2;
vector<MyTable> v1;
vector<MyTable> v2;
vector<string> header1;
vector<string> header2;

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tp;
    getline(cin, tp);
    n_t1 = stoi(tp);
    getline(cin, tp);
    string buff = "";
    for(int i = 0; i < tp.size(); i++){
       if(tp[i] != ' '){
           buff += tp[i];
       }else{
           header1.push_back(buff);
           buff = "";
       }
    }
    header1.push_back(buff);
    buff = "";
    for(int k = 0; k < n_t1-1; k++){
        int idx;
        cin >> idx;
        v1.push_back({});
        v1.back().idx = idx;
        for(int i = 1; i < header1.size(); i++){
            cin >> tp;
            v1.back().val.push_back(tp);
        }
    }
    cin.ignore();
    cin >> n_t2;
    cin.ignore();
    getline(cin, tp);
    buff = "";
    for(int i = 0; i < tp.size(); i++){
       if(tp[i] != ' '){
           buff += tp[i];
       }else{
           header2.push_back(buff);
           buff = "";
       }
    }
    header2.push_back(buff);
    buff = "";
    for(int k = 0; k < n_t2-1; k++){
        int idx;
        cin >> idx;
        v2.push_back({});
        v2.back().idx = idx;
        /* 두번 째 idx를 받자마자 테이블1에 idx같은 게 존재하나 확인 */
        int vSize1 = v1.size();
        int findIdx = -1;
        for(int t = 0; t < vSize1; t++){
            if(v1[t].idx == idx){
                findIdx = t;
            }
        }
        for(int i = 1; i < header2.size(); i++){
            cin >> tp;
            v2.back().val.push_back(tp);
            /* v1에 일치하는 idx가 있다면 찾은 v1idx의 val 값에 푸시한다 */
            if(findIdx != -1){
                v1[findIdx].val.push_back(tp);
            }
        }
    }

    /* v1을 idx에 따라 오름차순 정렬 */
    sort(v1.begin(), v1.end(), [](MyTable &t1, MyTable &t2)->bool{
        return (t1.idx < t2.idx);
    });

    /* 헤더 먼저 출력 */
    cout << "id" << " ";
    for(int i = 1; i < header1.size(); i++){
        cout << header1[i] << " ";
    }
    for(int i = 1; i < header2.size(); i++){
        cout << header2[i] << " ";
    }
    cout << '\n'; 

    /* v1 출력 */
    int vSize1 = v1.size();
    int hSize = header1.size() + header2.size() - 2;
    for(int i = 0; i < vSize1; i++){

        MyTable _thisV1 = v1[i];
        cout << _thisV1.idx << " ";
        int _count = hSize;
        for(auto it = _thisV1.val.begin(); it != _thisV1.val.end(); it++){
            _count--;
            cout << *it << " ";
        }
        while(_count-- != 0){
            cout << "NULL" << " ";
        }

        cout << '\n';

    }

    /* NULL 처리 해주어야 함 */

    return 0;
}