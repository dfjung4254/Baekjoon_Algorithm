#include <iostream>
#define MAX 123456
using namespace std;

int n;
bool matrix[MAX*2+1];

void setMatrix(){
    matrix[1] = true;
    for(int i = 1; i < MAX*2+1; i++){
        if(!matrix[i]){
            for(int j = i*2; j < MAX*2+1; j += i){
                matrix[j] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    setMatrix();
    while(n != 0){
        //calculate
        int ret = 0;
        int lim = 2*n;
        for(int i = n+1; i <= lim; i++){
            if(!matrix[i]){
                ret++;
            }
        }
        cout << ret << '\n';
        //end
        //new input.
        cin >> n;
    }


    return 0;
}