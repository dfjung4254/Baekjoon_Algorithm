#include <iostream>
using namespace std;

int matrix[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    matrix[1] = true;
    for(int i = 1; i < 10001; i++){
        if(!matrix[i]){
            for(int j = i*2; j < 10001; j += i){
                matrix[j] = true;
            }
        }
    }
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        int lTerm = n/2;
        int rTerm = n/2;
        while(lTerm > 1){
            if(!matrix[lTerm] && !matrix[rTerm]){
                break;
            }
            lTerm--;
            rTerm++;
        }
        cout << lTerm << " " << rTerm << '\n';
    }

    return 0;
}