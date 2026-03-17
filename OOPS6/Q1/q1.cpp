#include <iostream>
#include <cmath>
using namespace std;

class Shape{
protected:
    string color;
public:
    Shape(string color){
        this->color = color;
    }
    void displayColor(){
        cout << "Color: " << color << endl;
    }
};

class circle : public Shape{
private:
    double radius;
public:
    circle(double rad, string colorP) : Shape(colorP){
        radius = rad;
    }
    void area(){
        cout << "Area: " << M_PI * radius * radius << endl;
    }
};

int main(){
    circle c1(3, "Red");
    c1.Shape :: displayColor(); //Color attribute is not accessible in main() it is accessed using child class object
    c1.area(); //displayColor is accessible only because of child inheriting parent methods
    //Circle's radius is totally not accessible and is private to class itself
    //Circle area() member is easily accessible as it is public
}
