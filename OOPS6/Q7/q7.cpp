#include <iostream>
using namespace std;

class Vehicle {
protected:
    string regNo;
    string brand;
    double dailyRate;
public:
    Vehicle(string r, string b, double d) : regNo(r), brand(b), dailyRate(d) {}
    void display() {
        cout << "Registration No: " << regNo << endl;
        cout << "Brand: " << brand << endl;
        cout << "Daily Rate: " << dailyRate << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(int doors, string r, string b, double d) : Vehicle(r, b, d), numDoors(doors) {}
    void display() {
        Vehicle::display();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class ElectricCar : public Car {
private:
    double battCap;
public:
    ElectricCar(double bcap, int doors, string r, string b, double d) : Car(doors, r, b, d), battCap(bcap) {}
    void display() {
        Car::display();
        cout << "Battery Capacity: " << battCap << " kWh" << endl;
    }
    void calculateRentalCost(int days) {
        double discountedRate = dailyRate * 0.85;  // 15% green discount
        cout << "Rental Cost for " << days << " days: " << discountedRate * days << endl;
    }
};

class Truck : private Vehicle {
private:
    double payloadCapacity;
public:
    Truck(double payload, string r, string b, double d) : Vehicle(r, b, d), payloadCapacity(payload) {}
    void displayTruck() {
        Vehicle::display();
        cout << "Payload Capacity: " << payloadCapacity << " tonnes" << endl;
        // registrationNo cannot be accessed from main() via object
        // or by further derived classes because private inheritance
        // demotes all members to private, breaking the chain
        // But Truck itself CAN access regNo internally
    }
};

int main() {
    Car c1(4, "ABC-123", "Toyota", 50);
    ElectricCar e1(75.0, 4, "ELC-456", "Tesla", 80);
    Truck t1(10.5, "TRK-789", "Volvo", 120);

    cout << "--- Car ---" << endl;
    c1.display();

    cout << "\n--- Electric Car ---" << endl;
    e1.display();
    e1.calculateRentalCost(7);

    cout << "\n--- Truck ---" << endl;
    t1.displayTruck();
}
