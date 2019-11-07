#include <iostream>
#include <string>
using namespace std;

int n;
bool matrix[64][64] = {false, };

void dConquer(bool mat[][64], int size, int iOffset, int jOffset){

    int i_init = iOffset;
    int j_init = jOffset;
    int i_size = i_init + size;
    int j_size = j_init + size;

    bool sample = mat[i_init][j_init];
    bool isSame = true;
    for(int i = i_init; i < i_size; i++){
        for(int j = j_init; j < j_size; j++){
            if(mat[i][j] != sample){
                isSame = false;
            }
        }
    }

    if(size == 1 || isSame){
        cout << mat[i_init][j_init];
    }else{
        cout << "(";
        /* divide */
        int n_size = size / 2;
        int n_iOffset = (i_init + i_size) / 2;
        int n_jOffset = (j_init + j_size) / 2;
        dConquer(mat, n_size, i_init, j_init);
        dConquer(mat, n_size, i_init, n_jOffset);
        dConquer(mat, n_size, n_iOffset, j_init);
        dConquer(mat, n_size, n_iOffset, n_jOffset);
        cout << ")";
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string input;
        getline(cin, input);
        for(int j = 0; j < n; j++){
            int tp = input[j] - '0';
            matrix[i][j] = tp;
        }
    }

    dConquer(matrix, n, 0, 0);

    return 0;
}