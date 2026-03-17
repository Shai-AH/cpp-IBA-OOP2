#include <iostream>

using namespace std;

class vehicle{
protected:
    double rentalPricePerDay;
    string vehicleType;
public:
    vehicle(){};
    ~vehicle(){};
    virtual void rent(int days) = 0;
    void rent(int days, string paymentMethod) {
        cout << "Payment Method: " << paymentMethod << endl;
        rent(days);
    }
    void rent(int days, double paymentAmount) {
        cout << "Payment Paid: " << paymentAmount << endl;
        rent(days);
    }
    virtual void displayInfo(){
        cout << "Information: " << endl;
        cout << "Rental Price per day: " << rentalPricePerDay << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
    }
    string operator +(const vehicle& v1){
        if(rentalPricePerDay > v1.rentalPricePerDay) return vehicleType;
        else return v1.vehicleType;
    }
};

class car : public vehicle{
private:
    bool airConditioning;
    int numberofSeats;
public:
    car(int rents, string vehT, bool airC, int seats){
        rentalPricePerDay = rents;
        vehicleType = vehT;
        airConditioning = airC;
        numberofSeats = seats;
    }
    ~car(){};
    void rent(int days) override{
        if(days > 7){
            rentalPricePerDay = 0.90 * days * rentalPricePerDay;
        }
        else rentalPricePerDay = days * rentalPricePerDay;;
    }
    void displayInfo() override{
        cout << "Information: " << endl;
        cout << "Rental Price per day: " << rentalPricePerDay << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
        if(airConditioning) cout << "The Vehicle is Air-Conditioned!" << endl;
        else cout << "The Vehicle is NOT Air-Conditioned!" << endl;
        cout << "Number of Seats: " << numberofSeats << endl;
    }
};

class bike : public vehicle{
private:
    bool helmetIncluded;
    string fueltype;
public:
    bike(int rents, string vehT, bool helmet, string fuel){
        rentalPricePerDay = rents;
        vehicleType = vehT;
        helmetIncluded = helmet;
        fueltype = fuel;
    }
    ~bike(){};
    void rent(int days) override{
        if(days > 3){
            rentalPricePerDay = 0.95 * days * rentalPricePerDay;
        }
        else rentalPricePerDay = days * rentalPricePerDay;;
    }
    void displayInfo() override{
        cout << "Information: " << endl;
        cout << "Rental Price per day: " << rentalPricePerDay << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
        if(helmetIncluded) cout << "Helmet is included!" << endl;
        else cout << "Helmet is NOT included!" << endl;
        cout << "Fuel Type: " << fueltype << endl;
    }
};

class truck : public vehicle{
private:
    int cargoCapacity;
    int numberofWheels;
public:
    truck(int rents, string vehT, int cargo, int wheels){
        rentalPricePerDay = rents;
        vehicleType = vehT;
        cargoCapacity = cargo;
        numberofWheels = wheels;
    }
    ~truck(){};
    void rent(int days) override{
        if(days > 5) rentalPricePerDay = rentalPricePerDay * days * 1.20;
        else rentalPricePerDay = rentalPricePerDay * days;
    }
    void displayInfo() override{
        cout << "Information: " << endl;
        cout << "Rental Price per day: " << rentalPricePerDay << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Cargo Capacity: " << cargoCapacity << endl;
        cout << "Number of Wheels:  " << numberofWheels << endl;
    }
};



int main(){
    vehicle* v1 = new bike(100, "Bike", true, "Diesel");
    v1->rent(3, "EasyPaisa");
    v1->rent(3, 200);
    v1->displayInfo();
    cout << "\n";
    vehicle* v2 = new car(150, "Car", true, 5);
    v2->rent(3, "Online Transaction");
    v2->rent(3, 200);
    v2->displayInfo();
    string res = *v1 + *v2;

    cout << "The " << res << " rental is more expensive!" << endl;
}
