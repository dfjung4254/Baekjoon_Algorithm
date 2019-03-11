#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int n, k;
int matrix[500] = {0, };
long double minRet = 987654321;

long double getDisp(vector<int> v){

    long double m = 0;
    long double sum = 0;
    for(int num : v){
        sum += num;
    }
    int size = v.size();
    m = (long double)sum / size;

    long double d_sum = 0;
    for(int num : v){
        d_sum += pow(num - m, 2);
    }
    
    return sqrt((long double)d_sum / size);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> matrix[i];
    }

    for(int i = 0; i < n-k+1; i++){
        vector<int> vec;
        int j = i;
        for(; j < i+k; j++){
            vec.push_back(matrix[j]);        
        }
        do{
            long double sol = getDisp(vec);
            if(sol < minRet){
                minRet = sol;
            }
            vec.push_back(matrix[j]);
        }while(j++ < n);
    }

    
    cout << fixed << setprecision(11) << minRet << '\n';

    return 0;
}