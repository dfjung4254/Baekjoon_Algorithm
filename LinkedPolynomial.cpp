#include <iostream>
using namespace std;

template <class T> class Polynomial;
template <class T>
class PolyTerm{
    friend class Polynomial<T>;
private:
    int coef;
    int exp;
    PolyTerm<T> *link;
public:
    PolyTerm(int c, int e, PolyTerm<T> *l = NULL)
    :coef(c), exp(e), link(l){}
};
template <class T>
class Polynomial{
private:
    PolyTerm<T> *first;
    PolyTerm<T> *last;
public:
    Polynomial(PolyTerm<T> *fst = NULL, PolyTerm<T> *lst = NULL):first(fst), last(lst){}
    Polynomial operator+(const Polynomial &b) const;
    void insertPolyTerm(int coefv, int expv);
    void delPolyTerm(int delExp);
    void insertBack(int coefv, int expv);
    void print();
    int length();
};

int main(){

    Polynomial<int> *myPoly = new Polynomial<int>();
    myPoly->insertBack(1,4);
    myPoly->insertBack(2,3);
    myPoly->insertBack(3,2);
    myPoly->insertBack(4,1);
    myPoly->insertBack(5,0);
    myPoly->print();

    return 0;
}

template <class T>
int Polynomial<T>::length(){
    int count = 0;
    PolyTerm<T> *cur = first;
    while(cur){
        count++;
        cur = cur->link;
    }
    return count;
}
template <class T>
void Polynomial<T>::print(){
    cout << "Length : " << length() << endl;
    PolyTerm<T> *cur = first;
    while(cur){
        cout << cur->coef << "x^" << cur->exp;
        if(cur != last){
            cout << " + ";
        }
        cur = cur->link;
    }
    cout << endl;
}

template <class T>
void Polynomial<T>::insertBack(int coefv, int expv){
    PolyTerm<T> *newNode = new PolyTerm<T>(coefv, expv);
    if(first == NULL){
        first = newNode;
        last = newNode;
    }else{
        last->link = newNode;
        last = newNode;
    }
}
template <class T>
void Polynomial<T>::delPolyTerm(int delExp){
    PolyTerm<T> *cur = first;
    PolyTerm<T> *beforeCur = NULL;
    while(cur){
        if(cur->exp == delExp){
            if(cur == first){
                first = first->link;
                delete cur;
            }else if(cur == last){
                last = beforeCur;
                last->link = NULL;
                delete cur;
            }else{
                beforeCur->link = cur->link;
                delete cur;
            }
            return;
        }
        beforeCur = cur;
        cur = cur->link;
    }
}
template <class T>
void Polynomial<T>::insertPolyTerm(int coefv, int expv){

}
template <class T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial<T> &b) const{

}
