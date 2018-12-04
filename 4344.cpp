#include <iostream>
using namespace std;

class Line{
private:
    int size;
    int *score;
public:
    Line(){
        size = 0;
        score = NULL;
    }
    void setSize(int _size){
        size = _size;
        score = new int[size];
    }
    ~Line(){
        delete[] score;
    }
    void setScore(int index, int num){
        score[index] = num;
    }
    int getScore(int index){
        return score[index];
    }
    double getAverage(){
        int sum = 0;
        for(int i = 0; i < size; i++){
            sum += score[i];
        }
        return (double)sum / size;
    }
    double getPercentage(){
        double average = getAverage();
        int number = 0;
        for(int i = 0; i < size; i++){
            if(score[i] > average){
                number++;
            }
        }
        return ((double)number / size)*100.0;
    }
};

int main(){

    int lineSize;
    cin >> lineSize;
    Line line[lineSize];
    for(int i = 0; i < lineSize; i++){
        int size;
        cin >> size;
        line[i].setSize(size);
        for(int j = 0; j < size; j++){
            int num;
            cin >> num;
            line[i].setScore(j, num);
        }
    }
    for(int i = 0; i < lineSize; i++){
        cout.setf(ios::fixed);
        cout.precision(3);
        cout << line[i].getPercentage() << "%" << endl;
    }

    return 0;
}
