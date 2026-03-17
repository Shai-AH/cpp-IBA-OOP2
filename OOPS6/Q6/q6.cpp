#include <iostream>
using namespace std;

class HospitalStaff {
protected:
    int staffID;
    string name;
public:
    HospitalStaff(int id, string n) : staffID(id), name(n) {}
    string getRole() {
        return "Hospital Staff";
    }
};

class Doctor : public HospitalStaff {
private:
    string specialisation;
public:
    Doctor(int id, string n, string spec) : HospitalStaff(id, n), specialisation(spec) {}
    string getRole() {
        return "Doctor";
    }
    void prescribe(string patientName) {
        cout << "Dr. " << name << " prescribed medication to " << patientName << endl;
    }
};

class Nurse : public HospitalStaff {
private:
    string ward;
public:
    Nurse(int id, string n, string w) : HospitalStaff(id, n), ward(w) {}
    string getRole() {
        return "Nurse";
    }
    void assist(string doctorName) {
        cout << "Nurse " << name << " assisted " << doctorName << endl;
    }
};

class Administrator : protected HospitalStaff {
private:
    string officeLocation;
public:
    Administrator(int id, string n, string loc) : HospitalStaff(id, n), officeLocation(loc) {}
    void scheduleAppointment() {
        cout << "Appointment scheduled for staff " << name << " at " << officeLocation << endl;
    }
    // getRole() cannot be called in main because protected inheritance
    // demotes public members to protected, hiding them from outside access
};

int main() {
    Doctor d1(101, "Ali", "Cardiology");
    Nurse n1(102, "Sara", "ICU");
    Administrator a1(103, "Ahmed", "Block B");

    cout << d1.getRole() << endl;
    d1.prescribe("John");

    cout << n1.getRole() << endl;
    n1.assist("Dr. Ali");

    a1.scheduleAppointment();
    // a1.getRole();  // protected inheritance, not accessible in main
}
