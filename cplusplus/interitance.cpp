//abstract class
class Account
{
public:
    Account( double b ) { balance = b; }
    virtual ~Account() {} //destructor must be virtual
    virtual double getBalance() { return balance; }
    virtual double printAccountInfo() = 0; //pure virtual function needs to be implemented

private:
    double balance;
};

class CheckingAccount : public Account
{
public:
    CheckingAccount( double b ) : Account( b ) {}
    ~CheckingAccount() {}
    double printAccountInfo() { 
        cout << "Checking Account Balance: " << getBalance() << endl;
    }
};

class SavingAccount : public Account
{
public:
    SavingAccount( double b ) : Account( b ) {}
    ~SavingAccount() {}
    double printAccountInfo() { 
        cout << "Saving Account Balance: " << getBalance() << endl;
    }
};
