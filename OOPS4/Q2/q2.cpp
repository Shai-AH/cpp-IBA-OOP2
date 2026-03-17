#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
    node(int data=0){
        this->data = data;
        next = nullptr;
    }
    node(){
        next = nullptr;
    }
};
class Queue{
    node* fronts;
    node* rear;
public:
    Queue(){
        fronts = nullptr;
        rear = nullptr;
    }
    void enqueue(int data){
        node *newnode = new node(data);
        if(fronts == nullptr || rear == nullptr){
            fronts = newnode;
            rear = newnode;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
    }
    int dequeue(){
        if(fronts == nullptr || rear == nullptr){
            throw underflow_error("Empty");
            return 0;
        }
        else if(rear == fronts){
            node* temp = fronts;
            rear = nullptr;
            delete fronts;
            fronts = nullptr;
            return temp->data;

        }
        else{
            node* temp = fronts;
            fronts = fronts->next;
            int temps = temp->data;
            delete temp;
            return temps;
        }
    }
    void moveNthrear(int index){
        index = index - 1;
        int counter = 0;
        node* previous = nullptr;
        node* current = fronts;
        if(index == 0){
            fronts = fronts->next;
            rear->next = current;
            current->next = nullptr;
            rear = current;
        }
        else{
            while(index != counter && current != nullptr){
                previous = current;
                current = current->next;
                counter++;
                if(current == nullptr) return;
            }
            previous->next = current->next;
            rear->next = current;
            current->next = nullptr;
            rear = current;
        }
    }
    void printQueue(){
        node* temp = fronts;
        while(temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main(){
    Queue q1;
    q1.enqueue(0);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << "Queue Initially: " << endl;
    q1.printQueue();
    q1.moveNthrear(3);
    cout << "Queue After moving 3 position element to rear: " << endl;
    q1.printQueue();
}
