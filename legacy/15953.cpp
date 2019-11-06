#include <iostream>
using namespace std;

const int money_rank1[7] = {0, 5000000, 3000000, 2000000, 500000, 300000, 100000};
const int money_rank2[6] = {0, 5120000, 2560000, 1280000, 640000, 320000};

void calculate(int rank1, int rank2){

    int ch_rank1 = 0;
    int ch_rank2 = 0;

    if(rank1 == 0){
        ch_rank1 = 0;
    }else if(rank1 <= 1){
        ch_rank1 = 1;
    }else if(rank1 <= 3){
        ch_rank1 = 2;
    }else if(rank1 <= 6){
        ch_rank1 = 3;
    }else if(rank1 <= 10){
        ch_rank1 = 4;
    }else if(rank1 <= 15){
        ch_rank1 = 5;
    }else if(rank1 <= 21){
        ch_rank1 = 6;
    }else{
        ch_rank1 = 0;
    }

    if(rank2 == 0){
        ch_rank2 = 0;
    }else if(rank2 <= 1){
        ch_rank2 = 1;
    }else if(rank2 <= 3){
        ch_rank2 = 2;
    }else if(rank2 <= 7){
        ch_rank2 = 3;
    }else if(rank2 <= 15){
        ch_rank2 = 4;
    }else if(rank2 <= 31){
        ch_rank2 = 5;
    }else{
        ch_rank2 = 0;
    }

    cout << money_rank1[ch_rank1]+money_rank2[ch_rank2] << '\n';

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int a, b;
        cin >> a >> b;
        calculate(a, b);
    }

    return 0;
}