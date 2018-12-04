#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    setprecision(2);
    int n;
    cin >> n;
    int score[n];
    double ch_score[n];
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> score[i];
        if(max < score[i]){
            max = score[i];
        }
    }
    double sum;
    for(int i = 0; i < n; i++){
        ch_score[i] = (double) score[i] / max * 100;
        sum += ch_score[i];
    }
    cout << sum / n << endl;

    return 0;
}
