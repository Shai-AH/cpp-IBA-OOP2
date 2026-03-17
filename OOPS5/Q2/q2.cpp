#include <iostream>

using namespace std;

class shape{
private:
    int area;
public:
    void calArea(int num){
        area = num * num;
    }
    int operator+(const shape& s1){
        int Area = 0;
        Area = area + s1.area;
        return Area;
    }
};

int main(){
    shape s1;
    shape s2;
    s1.calArea(5); // 5 * 5 = 25
    s2.calArea(10); // 10 * 10 = 100
    int totalarea = s1 + s2; // 25 + 100 = 125
    cout << "Total Area: " << totalarea << endl;
}
