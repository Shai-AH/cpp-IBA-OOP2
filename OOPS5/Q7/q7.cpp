#include <iostream>

using namespace std;

class multiply{
public:
    multiply(){};
    int mult(int m1, int m2){
        return m1 * m2;
    }
    int mult(int m1, int m2, int m3){
        return m1 * m2 * m3;
    }
    double mult(double m1, double m2){
        return m1 * m2;
    }
    double mult(double m1, double m2, double m3){
        return m1 * m2 * m3;
    }
};

int main(){
    multiply calculate;
    cout << "Two Integers: "<< calculate.mult(1, 2) << endl;
    cout << "Three Integers: "<< calculate.mult(1, 2, 3) << endl;
    cout << "Two Decimal: "<< calculate.mult(1.1, 2.2) << endl;
    cout << "Three Decimal: "<< calculate.mult(1.1, 2.2, 3.3) << endl;
}
