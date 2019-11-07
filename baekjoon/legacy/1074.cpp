#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int _size;
int _count = 0;
int ret = 0;

void dConquer(int size, int iOffset, int jOffset){

    /*
    
        사이즈가 1이면 카운트 아니면 나눔
    
    */

    int i_end = iOffset + size;
    int j_end = jOffset + size;

    if(iOffset == r && jOffset == c){
        ret = _count;
    }

    if((r > i_end || r < iOffset) || (c > j_end || c < jOffset)){
        /* 탐색할 가지가 아니면 스킵함  */
        _count += pow(size, 2);
    }else if(size == 1){
        _count++;
    }else{
        int nSize = size / 2;
        int n_iOffset = (iOffset + i_end) / 2;
        int n_jOffset = (jOffset + j_end) / 2;
        dConquer(nSize, iOffset, jOffset);
        dConquer(nSize, iOffset, n_jOffset);
        dConquer(nSize, n_iOffset, jOffset);
        dConquer(nSize, n_iOffset, n_jOffset);
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> r >> c;
    _size = pow(2, n);
    
    dConquer(_size, 0, 0);
    cout << ret << '\n';

    return 0;
}