#include <iostream>

using namespace std;

class CircularDriveThru{
    int* data;
    int Front;
    int rear;
    int cap;
    int currentsize;
public:
    CircularDriveThru(int c){
        data = new int[c];
        Front = 0;
        rear = -1;
        cap = c;
        currentsize = 0;
    }
    ~CircularDriveThru(){
        delete[]data;
        cout << "---------------------------------------" << endl;
        cout << "DynamicArray destroyed and memory freed.\n";
    }
    void parkCar(int carNumber){
        if(cap == currentsize){
            cout << "Capacity Full!" << endl;
            return;
        }
        if(rear == cap - 1){
            rear = 0;
            data[rear] = carNumber;
            currentsize = currentsize + 1;
            cout << "Successfully Added CAR#" << carNumber << endl;
        }
        else{
            rear = rear + 1;
            data[rear] = carNumber;
            currentsize = currentsize + 1;
            cout << "Successfully Added CAR#" << carNumber << endl;
        }
    }
    void carLeaves(){
        if(currentsize == 0){
            cout << "All cars are already left!" << endl;
            return;
        }
        if(Front != rear){
            if(Front == cap - 1){
                int temp = data[Front];
                Front = 0;
                currentsize = currentsize - 1;
                cout << "Removed Car#" << temp << endl;
            }
            else{
                int temp = data[Front];
                Front = Front + 1;
                currentsize = currentsize - 1;
                cout << "Removed Car#" << temp << endl;
            }
        }
        else{                               //IF REAR = FRONT
            int temp = data[Front];
            Front = 0;
            rear = -1;
            currentsize = currentsize - 1;
            cout << "Removed Car#" << temp << endl;
            cout << "Queue is empty now!" << endl;
        }
    }
    int frontCar(){
        return data[Front];
    }
    int lastCar(){
        return data[rear];
    }
    void isEmpty(){
        if(currentsize == 0) cout << "No Car Parked!" << endl;
        else cout << "Parking not empty!" << endl;
    }
    void isFull(){
        if(currentsize == cap) cout << "Capacity Full!" << endl;
        else cout << "Space is still empty!" << endl;
    }
};

int main(){
    CircularDriveThru lane(3);
    lane.parkCar(101);
    lane.parkCar(102);
    lane.parkCar(103);
    lane.parkCar(104);
    lane.carLeaves();
    lane.parkCar(104);
}
