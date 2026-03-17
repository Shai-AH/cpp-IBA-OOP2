#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    string CNIC;
public:
    Person(string name, string CNIC) : name(name), CNIC(CNIC) {}
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
    }
};

class Student : public Person {
private:
    string rollNumber;
    double GPA;
public:
    Student(string name, string CNIC, string rollNumber, double GPA)
        : Person(name, CNIC), rollNumber(rollNumber), GPA(GPA) {}

    void displayInfo() {
        Person::displayInfo();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "GPA: " << GPA << endl;
    }
};

class Lecturer : public Person {
private:
    string employeeID;
    string department;
public:
    Lecturer(string name, string CNIC, string employeeID, string department)
        : Person(name, CNIC), employeeID(employeeID), department(department) {}

    void displayInfo() {
        Person::displayInfo();
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    Student s1("Ali Khan", "12345-6789012-3", "CS-101", 3.8);
    Lecturer l1("Dr. Ahmed", "98765-4321098-7", "EMP-501", "Computer Science");

    cout << "--- Student Info ---" << endl;
    s1.displayInfo();

    cout << "\n--- Lecturer Info ---" << endl;
    l1.displayInfo();

}
