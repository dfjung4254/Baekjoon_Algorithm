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

/* 소트 종류 */
enum
{
    EXCHANGE, MERGE, QUICK
};

void exchangeSort(vector<int> &v){
    int sz = v.size();
    for (int i = 0; i < sz - 1; i++){
        for (int j = i + 1; j < sz; j++){
            if(v[i] < v[j]){
                int tp = v[i];
                v[i] = v[j];
                v[j] = tp;
            }
        }
    }
}

int tp[10000000];

void merge(vector<int> &v, int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high){
        if(v[i] > v[j]){
            tp[k++] = v[i++];
        }else{
            tp[k++] = v[j++];
        }
    }
    while(i <= mid){
        tp[k++] = v[i++];
    } 
    while(j <= high){
        tp[k++] = v[j++];
    }
    for (int idx = low; idx <= high; idx++){
        v[idx] = tp[idx];
    }

}

void mergeSort(vector<int> &v, int low, int high){

    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, mid, high);
    }

}

void quickSort(vector<int> &v, int low, int high){

    if(low >= high){
        return;
    }

    int pivot = v[low];

    int i = low + 1;
    int j = high;
    while(i <= j){

        while(i <= high && v[i] <= pivot){
            i++;
        }
        while(j > low && v[j] >= pivot){
            j--;
        }

        if(i > j){
            int tp = v[j];
            v[j] = v[low];
            v[low] = tp;
        }else{
            int tp = v[i];
            v[i] = v[j];
            v[j] = tp;
        }

    }

    quickSort(v, low, j - 1);
    quickSort(v, j + 1, high);
}

int d1, d2, d3;
int rd1, rd2, rd3;
vector<int> vv;
int vSize[6];

void makeVector(vector<int> &v, int size, bool isRand){

    /* 오름차순 난수 생성 */
    v.clear();
    if(isRand){
        for (int i = 1; i <= size; i++){
            v.push_back(rand());
        }
    }else{
        for (int i = 1; i <= size; i++)
        {
            v.push_back(i);
        }
    }

}

/* getSortTime */
double gst(vector<int> &v, int sortType, bool isRand, int idx){

    makeVector(v, vSize[idx], isRand);

    /* time start */
    double ck = (double)clock();

    switch(sortType){
        case EXCHANGE:
            exchangeSort(v);
            break;
        case MERGE:
            mergeSort(v, 0, v.size() - 1);
            break;
        case QUICK:
            quickSort(v, 0, v.size() - 1);
            break;
        default:
            break;
    }

    /* time end */
    return (double)(clock() - ck) / CLOCKS_PER_SEC;
}

void printData()
{

    cout << '\t' << '\t' << "N=" << vSize[0] << '\t' << '\t' << "N=" << vSize[1] << '\t' << '\t' << "N=" << vSize[2] << '\n';
    cout << "Exchange Sort"
         << "\t" << gst(vv, EXCHANGE, false, 0) << '\t' << '\t' << gst(vv, EXCHANGE, false, 1) << '\t' << '\t' << gst(vv, EXCHANGE, false, 2) << '\n';
    cout << "Quick Sort"
         << "\t" << gst(vv, QUICK, false, 0) << '\t' << '\t' << gst(vv, QUICK, false, 1) << '\t' << '\t' << gst(vv, QUICK, false, 2) << '\n';
    cout << '\n';

    cout << '\t' << '\t' << '\t' << '\t' << "N=" << vSize[3] << '\t' << "N=" << vSize[4] << '\t' << "N=" << vSize[5] << '\n';
    double d_merge[3][3];
    double avg_merge[3];
    for (int i = 0; i < 3; i++){
        double sum = 0;
        for (int j = 0; j < 3; j++){
            d_merge[i][j] = gst(vv, MERGE, true, i + 3);
            sum += d_merge[i][j];
        }
        avg_merge[i] = sum / 3.0;
    }
    cout << "Merge Sort" << '\t' << "data1" << '\t' << '\t' << d_merge[0][0] << '\t' << '\t' << d_merge[1][0] << '\t' << '\t' << d_merge[2][0] << '\n';
    cout << '\t' << '\t' << "data2" << '\t' << '\t' << d_merge[0][1] << '\t' << '\t' << d_merge[1][1] << '\t' << '\t' << d_merge[2][1] << '\n';
    cout << '\t' << '\t' << "data3" << '\t' << '\t' << d_merge[0][2] << '\t' << '\t' << d_merge[1][2] << '\t' << '\t' << d_merge[2][2] << '\n';
    cout << '\t' << '\t' << "average" << '\t' << '\t' << avg_merge[0] << '\t' << '\t' << avg_merge[1] << '\t' << '\t' << avg_merge[2] << '\n';


    double d_quick[3][3];
    double avg_quick[3];
    for (int i = 0; i < 3; i++)
    {
        double sum = 0;
        for (int j = 0; j < 3; j++)
        {
            d_quick[i][j] = gst(vv, QUICK, true, i + 3);
            sum += d_quick[i][j];
        }
        avg_quick[i] = sum / 3.0;
    }
    cout << "Quick Sort" << '\t' << "data1" << '\t' << '\t' << d_quick[0][0] << '\t' << '\t' << d_quick[1][0] << '\t' << '\t' << d_quick[2][0] << '\n';
    cout << '\t' << '\t' << "data2" << '\t' << '\t' << d_quick[0][1] << '\t' << '\t' << d_quick[1][1] << '\t' << '\t' << d_quick[2][1] << '\n';
    cout << '\t' << '\t' << "data3" << '\t' << '\t' << d_quick[0][2] << '\t' << '\t' << d_quick[1][2] << '\t' << '\t' << d_quick[2][2] << '\n';
    cout << '\t' << '\t' << "average" << '\t' << '\t' << avg_quick[0] << '\t' << '\t' << avg_quick[1] << '\t' << '\t' << avg_quick[2] << '\n';
}

int main(){

    srand(static_cast<unsigned int>(time(0)));
    ifstream input;
    input.open("input.txt");
    cout << fixed;
    cout.precision(3);

    if (input.is_open())
    {
        for (int i = 0; i < 6; i++){
            int tc;
            input >> tc;
            vSize[i] = tc;
        }
        printData();
    }

    return 0;
}