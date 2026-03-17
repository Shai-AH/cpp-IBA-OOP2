#include <iostream>
using namespace std;

class Person {
protected:
    int employeeID;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }
    void displayData() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
    string name;
    double m_income;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> m_income;
    }
    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << m_income << endl;
        bonus();
    }
    void bonus() {
        double bonusAmount = m_income * 0.05;
        cout << "Bonus: " << bonusAmount << endl;
    }
};

class Accounts : public Person {
    string name;
    double m_income;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> m_income;
    }
    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << m_income << endl;
        bonus();
    }
    void bonus() {
        double bonusAmount = m_income * 0.05;
        cout << "Bonus: " << bonusAmount << endl;
    }
};

int main() {
    Admin admin;
    cout << "--- Admin Employee ---" << endl;
    admin.getData();
    admin.displayData();

    cout << endl;

    Accounts accounts;
    cout << "--- Accounts Employee ---" << endl;
    accounts.getData();
    accounts.displayData();

    return 0;
}
