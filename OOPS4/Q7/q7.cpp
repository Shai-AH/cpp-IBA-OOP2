#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int severity;
    int arrivalOrder;
};

class ERQueue {
private:
    Patient* data;
    int Size;
    int capacity;
    int arrivalCounter;

    void resize() {
        int newCap = capacity * 2;
        Patient* temp = new Patient[newCap];

        for(int i = 0; i < Size; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
        capacity = newCap;
    }

public:
    ERQueue(int cap = 10) {
        data = new Patient[cap];
        Size = 0;
        capacity = cap;
        arrivalCounter = 0;
    }

    ~ERQueue() {
        delete[] data;
    }

    void addPatient(string name, int severity) {
        if(Size == capacity) resize();

        data[Size].name = name;
        data[Size].severity = severity;
        data[Size].arrivalOrder = arrivalCounter;

        arrivalCounter++;
        Size++;
    }

    Patient treatNext() {
        if(Size == 0) {
            return {"", -1, -1};
        }

        int index = 0;

        for(int i = 1; i < Size; i++) {
            if(data[i].severity > data[index].severity) {
                index = i;
            }
            else if(data[i].severity == data[index].severity && data[i].arrivalOrder < data[index].arrivalOrder) {
                index = i;
            }
        }

        Patient next = data[index];

        for(int i = index; i < Size - 1; i++) {
            data[i] = data[i + 1];
        }

        Size--;

        return next;
    }

    Patient peekNext() {
        if(Size == 0) {
            return {"", -1, -1};
        }

        int index = 0;

        for(int i = 1; i < Size; i++) {
            if(data[i].severity > data[index].severity) {
                index = i;
            }
            else if(data[i].severity == data[index].severity && data[i].arrivalOrder < data[index].arrivalOrder) {
                index = i;
            }
        }

        return data[index];
    }

    bool isEmpty() {
        return Size == 0;
    }
};

int main() {
    ERQueue er;

    er.addPatient("Alice", 5);
    er.addPatient("Bob", 8);
    er.addPatient("Charlie", 8);
    er.addPatient("Dana", 3);

    cout << "Next patient: " << er.peekNext().name << endl;

    cout << "\nTreatment order:\n";

    while(!er.isEmpty()) {
        Patient p = er.treatNext();
        cout << p.name << " | Severity: " << p.severity << endl;
    }

    return 0;
}
