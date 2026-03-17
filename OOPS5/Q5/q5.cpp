#include <iostream>
#include <cmath>
using namespace std;

class Shape{
public:
    Shape(){};
    virtual ~Shape(){};
    virtual void calcArea() = 0;
};

class rectangle : public Shape{
    int height;
    int base;
public:
    rectangle(int height, int base){
        this->height = height;
        this->base = base;
    }
    ~rectangle(){};
    void calcArea() override {
        int area = base * height;
        cout << "The Area of Rectangle is: " << area << endl;
    }
};

class circle : public Shape{
    int rad;
public:
    circle(int rad){
        this->rad = rad;
    }
    ~circle(){};
    void calcArea() override {
        double area = (double) (rad * rad * M_PI);
        cout << "The Area of circle is: " << area << endl;
    }
};

class triangle : public Shape{
    double a;
    double b;
    double c;
public:
    triangle(double a, double b, double c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    ~triangle(){};
    void calcArea() override {
        double s = ((a + b + c) / 2);
        double area = (sqrt(s * (s - a) * (s - b) * (s - c)));
        cout << "The Area of Triangle is: " << area << endl;
    }
};

int main(){
    Shape* s1 = new triangle(1, 1, 1);
    Shape* s2 = new circle(1);
    Shape* s3 = new rectangle(1, 1);

    s1->calcArea();
    s2->calcArea();
    s3->calcArea();
}
