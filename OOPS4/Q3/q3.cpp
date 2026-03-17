#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct List{
    char data;
    List* next;
    List(char data){
        this->data = data;
        next = nullptr;
    }
    List(){
        next = nullptr;
    }
};

class Stack{
    List* top;
public:
    Stack() : top(nullptr){}


    void push(char val){
        List* newnode = new List(val);
        if(top == nullptr) top = newnode;
        else{
            newnode->next = top;
            top = newnode;
        }
    }

    char pop(){
        if(top == nullptr) throw underflow_error("The Stack is empty");
        else{
            List* temp = top;
            top = top->next;
            return temp->data;
        }
    }
    void printStack(){
        List* temp = top;
        while(temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    List* deleteNodes(string arr, int sizes){
        List* curr = top;
        List* prev = nullptr;
        for(int i = 0; i < sizes; i++){
                if(top->data == arr[i]){
                    List* temp = top;
                    top = top->next;
                    delete temp;
                }
                else{
                     while(curr != nullptr){
                        if(curr->data == arr[i]){
                            prev->next = curr->next;
                            delete curr;
                            break;
                        }
                        else{
                            prev = curr;
                            curr = curr -> next;
                        }
                    }
                    prev = nullptr;
                    curr = top;
                }
        }
        return top;
    }
};

int main(){
    Stack s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');
    s1.push('e');
    s1.push('f');
    s1.printStack();
    cout << "-------" << endl;
    char c1[] = "fcd";
    s1.deleteNodes(c1, 3);
    s1.printStack();
}

