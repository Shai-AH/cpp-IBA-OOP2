#include <iostream>

using namespace std;

class Employee{
protected:
    int employeeID;
    double baseSalary;
public:
    Employee(int ID, double salary){
        employeeID = ID;
        baseSalary = salary;
    }
    virtual int getBonus(){
        return 0.05 * baseSalary;
    }
    virtual void display(){
        cout << "ID: " << employeeID << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Bonus: " << getBonus() << endl;
    }
};

class Manager : public Employee{
private:
    string department;
public:
    Manager(string dept, int ID, double salary) : department(dept), Employee(ID, salary){}
    int getBonus() override{
        return 0.10 * baseSalary;
    }
    void display() override{
        Employee :: display();
        cout << "Department: " << department << endl;
    }
};

class RegionalDirector : public Manager{
private:
    string region;
public:
    RegionalDirector(string regionP, string dept, int ID, double salary) : region(regionP), Manager(dept, ID, salary){}
    int getBonus() override{
        return 0.15 * baseSalary;
    }
    void display() override{
        Manager :: display();
        cout << "Region: " << region << endl;
    }
};

int main(){
    Employee e1(111, 100);
    Manager m1("Office", 112, 150);
    RegionalDirector r1("Karachi", "Main Office", 001, 200);
    e1.display();
    cout << endl;
    m1.display();
    cout << endl;
    r1.display();
    cout << endl;
}
