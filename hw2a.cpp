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

void merge(vector<int> &v, int low1, int high1, int low2, int high2)
{
    int init = low1;
    int end = high2;
    vector<int> nv;
    while (low1 <= high1 && low2 <= high2)
    {
        if (v[low1] > v[low2])
        {
            nv.push_back(v[low2++]);
        }
        else
        {
            nv.push_back(v[low1++]);
        }
    }
    while (low1 <= high1)
    {
        nv.push_back(v[low1++]);
    }
    while (low2 <= high2)
    {
        nv.push_back(v[low2++]);
    }

    int idx = 0;
    for (int i = init; i <= end; i++)
    {
        v[i] = nv[idx++];
    }
}

void mergeSort(vector<int> &v, int size, int low, int high){

    if(size == 1){
        return;
    }
    int mid = (low + high) / 2;
    int n_size = size / 2;
    mergeSort(v, size - n_size, low, mid);
    mergeSort(v, n_size, mid + 1, high);
    merge(v, low, mid, mid + 1, high);
}

void swap(vector<int> &v, int a, int b){

    int tp = v[a];
    v[a] = v[b];
    v[b] = tp;

}

void quickSort(vector<int> &v, int low, int high){

    int pivot = v[low];

    if(low < high){
        /* 먼저 파티션 한다 */
        int i, j;
        for (int i = low + 1; i <= high; i++){
            
        }
    }
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
    for (int i = 10000; i > 0; i--){
        vv.push_back(i);
    }
    
    //mergeSort(vv, vv.size(), 0, vv.size() - 1);
    cout << exchangeSort(vv) << '\n';
    for (int i = 0; i < vv.size(); i++){
        cout << vv[i] << " ";
    }

        return 0;
}