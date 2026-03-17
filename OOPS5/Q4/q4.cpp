#include <iostream>

using namespace std;

class Payment{
public:
    void processPayment(){
        cout << "Processing a generic payment." << endl;
    }
};

class CreditCardPayment : public Payment{
public:
    void processPayment(){
        cout << "Processing payment via Credit Card." << endl;
    }
};

class PayPalPayment : public Payment{
public:
    void processPayment(){
        cout << "Processing payment via PayPal" << endl;
    }
};

class CryptoPayment : public Payment{
public:
    void processPayment(){
        cout << "Processing payment via Cryptocurrency." << endl;
    }
};

int main(){
    CreditCardPayment c1;
    PayPalPayment p1;
    CryptoPayment cr1;

    c1.processPayment();
    c1.Payment :: processPayment();
    p1.processPayment();
    p1.Payment :: processPayment();
    cr1.processPayment();
    cr1.Payment :: processPayment();
}
