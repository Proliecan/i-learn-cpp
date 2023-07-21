#include <string>
using std::string;

#include <vector>
using std::vector;

#include <print.h>

class Transaction
{
private:
    int amount;
    string type;

public:
    Transaction(int amount, string type);
    ~Transaction();
    string Report();
};

class Account
{
private:
    /* data */
    string firstName;
    string lastName;

    int balance;
    vector<Transaction> log;

public:
    Account(string firstName, string lastName);
    ~Account();

    vector<string> Report();
    bool Deposit(int amount);
    bool Withdraw(int amount);
    int GetBalance() { return balance; }
};


#pragma region account

Account::Account(string firstName, string lastName) : balance(0)
{
    this->firstName = firstName;
    this->lastName = lastName;
}

Account::~Account()
{
}

vector<string> Account::Report()
{
    vector<string> report;

    report.push_back("Balance is " + std::to_string(balance));
    report.push_back("Transactions: ");

    for (auto t : log)
    {
        report.push_back(t.Report());
    }

    return report;
}

bool Account::Deposit(int amount)
{
    if (amount <= 0)
    {
        return false;
    }

    balance += amount;

    log.push_back(Transaction(amount, "Deposit"));
    return true;
}

bool Account::Withdraw(int amount)
{
    if (amount <= 0)
    {
        return false;
    }
    if (Account::balance >= amount)
    {
        balance -= amount;

        log.push_back(Transaction(amount, "Withdrawal"));
        return true;
    }
    return false;
}

#pragma endregion

#pragma region Transaction
Transaction::Transaction(int amount, string type) : amount(amount), type(type) {}

Transaction::~Transaction()
{
}

string Transaction::Report()
{
    return string(type + ": " + std::to_string(amount));
}

#pragma endregion

int main(int argc, char const *argv[])
{
    Account account("Emil", "Heinz");

    account.Deposit(2000);
    account.Withdraw(20);
    account.Withdraw(10);
    account.Withdraw(200);
    account.Withdraw(2000);
    account.Withdraw(-1);
    account.Deposit(-1);
    account.Deposit(INT32_MAX);
    vector<string> report = account.Report();

    for (auto l:report){
        print(l);
    }

    return 0;
}
