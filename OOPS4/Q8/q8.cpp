#include <iostream>
#include <string>
using namespace std;

struct Plane {
    string flight;
    int severity;
    int arrival;
};

class TakeoffStack {
    Plane* data;
    int Top;
    int capacity;

    void resize() {
        int newCap = capacity * 2;
        Plane* temp = new Plane[newCap];

        for(int i = 0; i < Top; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
        capacity = newCap;
    }

public:
    TakeoffStack(int cap = 10) {
        data = new Plane[cap];
        Top = 0;
        capacity = cap;
    }

    ~TakeoffStack() {
        delete[] data;
    }

    void push(string flight, int arrival) {
        if(Top == capacity) resize();

        data[Top].flight = flight;
        data[Top].arrival = arrival;
        Top++;
    }

    Plane pop() {
        if(Top == 0) return {"", -1, -1};

        Top--;
        return data[Top];
    }

    bool isEmpty() {
        return Top == 0;
    }
};

class LandingQueue {
private:
    Plane* data;
    int Size;
    int capacity;

    void resize() {
        int newCap = capacity * 2;
        Plane* temp = new Plane[newCap];

        for(int i = 0; i < Size; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
        capacity = newCap;
    }

public:
    LandingQueue(int cap = 10) {
        data = new Plane[cap];
        Size = 0;
        capacity = cap;
    }

    ~LandingQueue() {
        delete[] data;
    }

    void add(string flight, int severity, int arrival) {
        if(Size == capacity) resize();

        data[Size].flight = flight;
        data[Size].severity = severity;
        data[Size].arrival = arrival;

        Size++;
    }

    Plane removeHighest() {
        if(Size == 0) return {"", -1, -1};

        int index = 0;

        for(int i = 1; i < Size; i++) {
            if(data[i].severity > data[index].severity) {
                index = i;
            }
            else if(data[i].severity == data[index].severity &&
                    data[i].arrival < data[index].arrival) {
                index = i;
            }
        }

        Plane best = data[index];

        for(int i = index; i < Size - 1; i++) {
            data[i] = data[i + 1];
        }

        Size--;

        return best;
    }

    bool isEmpty() {
        return Size == 0;
    }
};

class ControlTower {
private:
    TakeoffStack takeoff;
    LandingQueue landing;
    int timer;

public:
    ControlTower() {
        timer = 0;
    }

    void normalTakeoff(string flight) {
        takeoff.push(flight, timer);
        timer++;
    }

    void emergencyLanding(string flight, int severity) {
        landing.add(flight, severity, timer);
        timer++;
    }

    void nextAction() {
        if(!landing.isEmpty()) {
            Plane p = landing.removeHighest();
            cout << "Land: " << p.flight
                 << " (Severity " << p.severity << ")\n";
        }
        else if(!takeoff.isEmpty()) {
            Plane p = takeoff.pop();
            cout << "Take off: " << p.flight << endl;
        }
        else {
            cout << "No planes waiting\n";
        }
    }
};

int main() {

    ControlTower tower;

    tower.normalTakeoff("AB123");
    tower.normalTakeoff("CD456");
    tower.normalTakeoff("EF789");

    tower.emergencyLanding("GH101", 9);
    tower.emergencyLanding("IJ202", 10);
    tower.emergencyLanding("KL303", 8);

    tower.nextAction();
    tower.nextAction();
    tower.nextAction();
    tower.nextAction();
    tower.nextAction();
    tower.nextAction();

    return 0;
}
