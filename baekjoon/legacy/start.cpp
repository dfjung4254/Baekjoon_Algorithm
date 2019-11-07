#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int flag = (n + 1) / 2;
    for (int i = 1; i <= n; i++){

        int space_offset = i - flag;
        if(space_offset < 0){
            space_offset = -space_offset;
        }

        for (int j = 0; j < space_offset; j++){
            cout << " ";
        }

        int star_offset = i * 2 - 1;
        if(i > flag){
            star_offset = ((n + 1) - i) * 2 - 1;
        }
        for (int j = 0; j < star_offset; j++){
            cout << "*";
        }
        cout << '\n';
    }

        return 0;
}