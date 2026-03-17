#include <iostream>
using namespace std;

class Stack {
private:
    int* data;
    int capacity;
    int sizes;
    int top;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i <= top; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Stack(int capacity = 10) {
        this->capacity = capacity;
        data = new int[capacity];
        sizes = 0;
        top = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (sizes == capacity) {
            resize();
        }
        data[++top] = value;
        sizes++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty. Cannot pop." << endl;
            exit(1);
        }
        sizes--;
        return data[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty. Cannot peek." << endl;
            exit(1);
        }
        return data[top];
    }

    bool isEmpty() {
        return sizes == 0;
    }

    int getSize() {
        return sizes;
    }

    string toString() {
        string result = "[";
        for (int i = 0; i <= top; i++) {
            result += to_string(data[i]);
            if (i != top) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }
    void reverseMiddleHalf(){
        if(sizes % 2 == 1){
            int half = sizes/2;
            int i = half - (half/2);
            int j = half + (half/2);
            for(int k = i; k < j + 1; k++){
                int temp = data[k];
                data[k] = data[j];
                data[j] = temp;
                j--;
            }
        }
        else if(sizes % 4 == 0){
            int half = sizes/2;
            int j = half + (half/2 - 1);
            int i = half - (half/2);
            for(int k = i; k < j + 1; k++){
                int temp = data[k];
                data[k] = data[j];
                data[j] = temp;
                j--;
            }
        }
        else{
            int half = sizes/2;
            int j = half + (half/2 - 1);
            int i = half - (half/2 + 1);
            for(int k = i; k < j + 1; k++){
                int temp = data[k];
                data[k] = data[j];
                data[j] = temp;
                j--;
            }
        }
    }
    bool operator < (const Stack& s1){
        if(sizes < s1.sizes){
            return true;
        }
        else if(sizes > s1.sizes){
            return false;
        }
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < sizes; i++){
            sum1 = sum1 + data[i];
            sum2 = sum2 + s1.data[i];
        }
        if(sum1 < sum2){
            return true;
        }
        else if(sum1 == sum2){
            if(top < s1.top){
                return true;
            }
            else if(top > s1.top){
                return false;
            }
        }
        else{
            return false;
        }
    }
};


int main(){
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    cout << s.toString() << endl;
    s.reverseMiddleHalf();
    cout << s.toString() << endl;

    Stack A(3);
    A.push(10);
    A.push(20);
    A.push(30);
    Stack B(2);
    B.push(5);
    B.push(15);
    bool res = A < B; //True = B Great | False = A Great
    if(res) cout << "B is greater!" << endl;
    else cout << "A is Greater!" << endl;

    Stack C(3);
    C.push(5);
    C.push(10);
    C.push(20);
    res = A < C; //True = B Great | False = A Great
    if(res) cout << "B is greater!" << endl;
    else cout << "A is Greater!" << endl;
}
