#include <iostream>

using namespace std;

class opOverload{
private:
    int num;
public:
    opOverload(int num){
        this->num = num;
    }
    void operator--(){
        num = num * 4;
    }
    void operator--(int){
        num = num / 4;
    }
    int getNum(){
        return num;
    }
};

int main(){
    opOverload o1(5);
    --o1;
    cout << o1.getNum() << endl;
    o1--;
    cout << o1.getNum() << endl;
}
