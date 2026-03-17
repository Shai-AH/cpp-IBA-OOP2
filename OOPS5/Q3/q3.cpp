#include <iostream>

using namespace std;

class footballGround{
private:
    int sqrside;
protected:
    int getSide(){
        return sqrside;
    }
public:
    footballGround(int side){
        sqrside = side;
    }
    int calArea(){
        return sqrside * sqrside;
    }
};

class cricketGround : public footballGround{
private:
    int side1;
    int side2;
public:
    cricketGround(int side): footballGround(side){
        side1 = getSide();
        side2 = 2 * getSide();
    }
    int calArea(){
        return side1 * side2;
    }
};

class robotGround : public footballGround{
private:
    double rad;
public:
    robotGround(int side): footballGround(side){
        rad = getSide();
    }
    double calArea(){
        return 3.147 * rad * rad;
    }
};

int main(){
    footballGround f1(5);
    cricketGround c1(5);
    robotGround r1(5);
    cout << f1.calArea() << endl;
    cout << c1.calArea() << endl;
    cout << r1.calArea() << endl;
}
