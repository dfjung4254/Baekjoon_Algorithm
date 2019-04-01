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
            if(v[i] > v[j]){
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
        if(v[i] < v[j]){
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

int ct = 0;

void quickSort(vector<int> &v, int low, int high){

    int i, j;
    int tp;
    int pivot = v[low];
    if(low < high){
        i = low;
        j = high + 1;
        while(i <= j){
            do{
                i++;
            } while (v[i] < pivot);
            do{
                j--;
            } while (v[j] > pivot);
            if(i < j){
                tp = v[i];
                v[i] = v[j];
                v[j] = tp;
            }else{
                break;
            }
        }
        tp = v[j];
        v[j] = v[low];
        v[low] = tp;
        quickSort(v, low, j - 1);
        quickSort(v, j + 1, high);
    }

    // if(ct > 100){
    //     return;
    // }

    // if(low >= high){
    //     return;
    // }

    // int pivot = v[low];

    // int i = low + 1;
    // int j = high;
    // while(i <= j){
        
    //     while(i <= high && v[i] <= pivot){
    //         i++;
    //     }
    //     while(j > low && v[j] >= pivot){
    //         j--;
    //     }

    //     if(i > j){
    //         int tp = v[j];
    //         v[j] = v[low];
    //         v[low] = tp;
    //     }else{
    //         int tp = v[i];
    //         v[i] = v[j];
    //         v[j] = tp;
    //     }

    // }

    // quickSort(v, low, j - 1);
    // quickSort(v, j + 1, high);

}

int d1, d2, d3;
int rd1, rd2, rd3;
vector<int> vv[6];
int vSize[6];

void re_shuffle(vector<int> &v){
    // unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // shuffle(v.begin(), v.end(), default_random_engine(seed));

    // int sz = v.size();
    // cout << rand() % sz << '\n';

    int sz = v.size();
    for (int i = 0; i < sz; i++){
        int s1 = rand() % sz;
        int s2 = rand() % sz;
        int tp = v[s1];
        v[s1] = v[s2];
        v[s2] = tp;
    }
}

void makeVector(vector<int> &v, int size){

    /* 오름차순 난수 생성 */
    for (int i = 1; i <= size; i++)
    {
        v.push_back(i);
    }

}


/* getSortTime */
double gst(vector<int> &v, int sortType, bool isRand){

    /* 벡터 복사 */
    vector<int> nv;
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        nv.push_back(v[i]);
    }

    if(isRand){
        re_shuffle(nv);
    }

    /* time start */
    clock_t ck = clock();

    switch(sortType){
        case EXCHANGE:
            exchangeSort(nv);
            break;
        case MERGE:
            mergeSort(nv, 0, nv.size() - 1);
            break;
        case QUICK:
            quickSort(nv, 0, nv.size() - 1);
            break;
        default:
            break;
    }

    /* time end */
    return (double)clock() - ck;
}

void printData()
{

    cout << '\t' << '\t' << "N=" << vSize[0] << '\t' << '\t' << "N=" << vSize[1] << '\t' << '\t' << "N=" << vSize[2] << '\n';
    cout << "Exchange Sort"
         << "\t" << gst(vv[0], EXCHANGE, false) << '\t' << '\t' << gst(vv[1], EXCHANGE, false) << '\t' << '\t' << gst(vv[2], EXCHANGE, false) << '\n';
    cout << "Quick Sort"
         << "\t" << gst(vv[0], QUICK, true) << '\t' << '\t' << gst(vv[1], QUICK, true) << '\t' << '\t' << gst(vv[2], QUICK, true) << '\n';
    cout << '\n';



    cout << '\t' << '\t' << '\t' << '\t' << "N=" << vSize[3] << '\t' << "N=" << vSize[4] << '\t' << "N=" << vSize[5] << '\n';
    double d_merge[3][3];
    double avg_merge[3];
    for (int i = 0; i < 3; i++){
        double sum = 0;
        for (int j = 0; j < 3; j++){
            d_merge[i][j] = gst(vv[i + 3], MERGE, true);
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
            d_quick[i][j] = gst(vv[i + 3], QUICK, true);
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

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(static_cast<unsigned int>(time(0)));
    ifstream input;
    input.open("input.txt"); 

    if (input.is_open())
    {
        for (int i = 0; i < 6; i++){
            int tc;
            input >> tc;
            vSize[i] = tc;
            makeVector(vv[i], tc);
        }
        printData();
    }

    // for (int i = 0; i < 10000; i++){
    //     vv[0].push_back(i + 1);
    // }
    // re_shuffle(vv[0]);
    // for(int a : vv[0]){
    //     cout << a << " ";
    // }
    // cout << '\n';
    // cout << '\n';
    // quickSort(vv[0], 0, vv[0].size() - 1);
    // for(int a : vv[0]){
    //     cout << a << " ";
    // }

    return 0;
}