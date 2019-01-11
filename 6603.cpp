#include <iostream>
using namespace std;

int nums[13];
int matrix[13];
int n;

void combination(int matrix[], int tn, int tr, int index, int tcount){
    if(tr <= index){
        //end
        for(int i = 0; i < tr; i++){
            cout << nums[matrix[i]] << " ";
        }
        cout << '\n';
        return;
    }
    if(tcount >= tn){
        return;
    }
    matrix[index] = tcount;
    //cout << "index : " << index << " / tcount : " << tcount << " .. saved!" << '\n';
    combination(matrix, tn, tr, index+1, tcount+1);
    combination(matrix, tn, tr, index, tcount+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        combination(matrix, n, 6, 0, 0);
        cout << '\n';
    }

    return 0;
}