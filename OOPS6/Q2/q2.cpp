#include <iostream>

using namespace std;

class BankAccount{
private:
    double balance;
public:
    void setBalance(double n){
        balance = n;
    }
    double& getBalance(){
        return balance;
    }
};

class SavingAccount : protected BankAccount{
public:
    SavingAccount(double n) {
        setBalance(n);
    }
    void addInterest(double rate){
        getBalance() = getBalance() * (1 + (rate / 100));
    }
};

int main(){
    SavingAccount s1(300);
    s1.addInterest(12);
//    s1.BankAccount :: getBalance();
//Cannot call getBalance as it is public->protected and it is only accessible in class itself
}
