/*
*   Algorithm Programming Assignment #2
*   Professor : 정균락 교수님
*   class : 알고리즘 분석 - 1
*   Student No : B354025
*   Name : 정근화
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

double exchangeSort(vector<int> &v){
    /* time start */
    clock_t ck = clock();
    int sz = v.size();
    for (int i = 0; i < sz - 1; i++){
        for (int j = i + 1; j < sz; j++){
            if(v[i] > v[j]){
                int tp = v[i];
                v[i] = v[j];
                v[j] = tp;
            }
        }
    }
    /* time end */
    return (double)clock() - ck;
}

void mergeSort(vector<int> &v){



}

void quickSort(vector<int> &v){



}

int d1, d2, d3;
int rd1, rd2, rd3;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(static_cast<unsigned int>(time(0)));

    ifstream input;
    input.open("input.txt");

    if (input.is_open())
    {
        int tc;
        input >> tc;


    }
    vector<int> vv;
    for (int i = 0; i < d1; i++){
        vv.push_back(rand());
    }
    cout << exchangeSort(vv) << '\n';
    for (int i = 0; i < vv.size(); i++){
        cout << vv[i] << " ";
    }

        return 0;
}