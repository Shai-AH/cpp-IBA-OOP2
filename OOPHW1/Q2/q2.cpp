#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

struct SensorReading{
    int sensorId;
    string location;
    string sensorType;
    double value;

    SensorReading(){}

    SensorReading(int sensorId, string location, string sensorType, double value){
        this->sensorId = sensorId;
        this->location = location;
        this->sensorType = sensorType;
        this->value = value;
    }
};

struct Alert{
    int priority;
    string message;
    string alertType;
};

struct cmp {
    bool operator()(const Alert& a, const Alert& b) {
        return a.priority < b.priority;  // higher priority first
    }
};

class sensorProcessor{

    unordered_map<int, SensorReading> umap;                 // ID lookup
    unordered_map<string, vector<SensorReading>> locationmap; // Location grouping
    priority_queue<Alert, vector<Alert>, cmp> pq;            // Alerts

public:


    void addSensorReading(const SensorReading& reading){


        umap[reading.sensorId] = reading;


        locationmap[reading.location].push_back(reading);
    }

    void addAlert(const Alert& alert){
        pq.push(alert);
    }


    void processNextAlert(){

        if(pq.empty()){
            cout << "No alert exists!" << endl;
            return;
        }

        Alert a1 = pq.top();
        pq.pop();

        cout << "\n--- Processing Alert ---\n";
        cout << "Priority: " << a1.priority << endl;
        cout << "Type: " << a1.alertType << endl;
        cout << "Message: " << a1.message << endl;
    }


    SensorReading* findSensorById(int sensorId){

        if(umap.find(sensorId) == umap.end()){
            cout << "Reading not found!" << endl;
            return nullptr;
        }

        return &umap[sensorId];
    }


    void getSensorsByLocations(const string& location){

        if(locationmap.find(location) == locationmap.end()){
            cout << "No sensors found at this location!" << endl;
            return;
        }

        cout << "\n--- Sensors at " << location << " ---\n";

        vector<SensorReading>& v1 = locationmap[location];

        for(int i = 0; i < v1.size(); i++){

            cout << "Sensor " << i + 1 << endl;
            cout << "ID: " << v1[i].sensorId << endl;
            cout << "Type: " << v1[i].sensorType << endl;
            cout << "Value: " << v1[i].value << endl;
            cout << "----------------------\n";
        }
    }
};


int main(){

    sensorProcessor system;


    system.addSensorReading(SensorReading(1001, "Adamjee Building", "Temperature", 32.5));
    system.addSensorReading(SensorReading(1002, "Adamjee Building", "Humidity", 65.2));
    system.addSensorReading(SensorReading(1003, "AMAN CED", "Proximity", 88.4));
    system.addSensorReading(SensorReading(1004, "Tabba Academic Building", "Smoke", 12.6));


    cout << "\n--- Finding Sensor ---\n";
    SensorReading* s = system.findSensorById(1002);

    if(s != nullptr){
        cout << "Found Sensor:\n";
        cout << "ID: " << s->sensorId << endl;
        cout << "Location: " << s->location << endl;
        cout << "Type: " << s->sensorType << endl;
        cout << "Value: " << s->value << endl;
    }


    system.getSensorsByLocations("Adamjee Building");
    system.getSensorsByLocations("AMAN CED");

    system.addAlert({5, "Temperature too high", "WARNING"});
    system.addAlert({10, "Fire detected", "CRITICAL"});
    system.addAlert({3, "Humidity normal", "INFO"});

    system.processNextAlert();
    system.processNextAlert();
    system.processNextAlert();
    system.processNextAlert();

    return 0;
}
