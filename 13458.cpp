#include <iostream>
using namespace std;

int n, b, c;
long long count = 0;

void getRet(int a[], int size){

    for(int i = 0; i < size; i++){
        int cur = a[i]-b;
        count++;
        if(cur < 0){
            continue;
        }
        int tar;
        if(cur%c == 0){
            tar = cur/c;
        }else{
            tar = cur/c +1;
        }
        count += tar;
    }

}

int main(){

    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> b >> c;
    getRet(a, n);
    cout << count << endl;


    return 0;
}
