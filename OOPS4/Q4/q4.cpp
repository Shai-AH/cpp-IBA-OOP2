#include <iostream>
using namespace std;

struct Record {
    int timestamp;
    int price;
};

class StockPrice {
private:
    Record* data;
    int Size;
    int capacity;
    int latestTime;

    void resize() {
        int newCap = capacity * 2;
        Record* temp = new Record[newCap];

        for(int i = 0; i < Size; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
        capacity = newCap;
    }

    int findIndex(int timestamp) {
        for(int i = 0; i < Size; i++) {
            if(data[i].timestamp == timestamp) {
                return i;
            }
        }
        return -1;
    }

public:
    StockPrice(int cap = 10) {
        data = new Record[cap];
        Size = 0;
        capacity = cap;
        latestTime = -1;
    }

    ~StockPrice() {
        delete[] data;
    }

    void update(int timestamp, int price) {

        int index = findIndex(timestamp);

        if(index != -1) {
            data[index].price = price;
        }
        else {
            if(Size == capacity) resize();

            data[Size].timestamp = timestamp;
            data[Size].price = price;
            Size++;
        }

        if(timestamp > latestTime) {
            latestTime = timestamp;
        }
    }

    int current() {

        int result = -1;

        for(int i = 0; i < Size; i++) {
            if(data[i].timestamp == latestTime) {
                result = data[i].price;
                break;
            }
        }

        return result;
    }

    int maximum() {

        int maxVal = data[0].price;

        for(int i = 1; i < Size; i++) {
            if(data[i].price > maxVal) {
                maxVal = data[i].price;
            }
        }

        return maxVal;
    }

    int minimum() {

        int minVal = data[0].price;

        for(int i = 1; i < Size; i++) {
            if(data[i].price < minVal) {
                minVal = data[i].price;
            }
        }

        return minVal;
    }
};

int main() {

    StockPrice stockPrice;

    stockPrice.update(1, 10);
    stockPrice.update(2, 5);

    cout << "Current: " << stockPrice.current() << endl;
    cout << "Maximum: " << stockPrice.maximum() << endl;

    stockPrice.update(1, 3);

    cout << "Maximum: " << stockPrice.maximum() << endl;

    stockPrice.update(4, 2);

    cout << "Minimum: " << stockPrice.minimum() << endl;

    return 0;
}
