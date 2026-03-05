#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNum, string name, double initialBalance)
        : accountNumber(accNum), accountHolderName(name), balance(initialBalance) {
        cout << "Account created successfully.\n";
    }

    ~BankAccount() {
        cout << "Account " << accountNumber << " closed.\n";
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
        }
        else if (amount > balance) {
            cout << "Insufficient balance.\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }

    bool transfer(BankAccount &other, double amount) {
        if (amount <= 0) {
            cout << "Invalid amount.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient balance.\n";
            return false;
        }

        balance -= amount;
        other.balance += amount;
        cout << "Transfer successful.\n";
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void displayAccount() const {
        cout << "\nAccount Number: " << accountNumber
             << "\nAccount Holder: " << accountHolderName
             << "\nBalance: $" << balance << "\n";
    }
};

// Helper function to find account
int findAccount(const vector<BankAccount>& accounts, const string& accNum) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum)
            return i;
    }
    return -1;
}

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. Check Balance\n";
        cout << "6. Display All Accounts\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string accNum, name;
            double balance;

            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            accounts.emplace_back(accNum, name, balance);
        }

        else if (choice == 2) {
            string accNum;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNum;

            int index = findAccount(accounts, accNum);
            if (index != -1) {
                cout << "Enter Amount: ";
                cin >> amount;
                accounts[index].deposit(amount);
            } else {
                cout << "Account not found.\n";
            }
        }

        else if (choice == 3) {
            string accNum;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNum;

            int index = findAccount(accounts, accNum);
            if (index != -1) {
                cout << "Enter Amount: ";
                cin >> amount;
                accounts[index].withdraw(amount);
            } else {
                cout << "Account not found.\n";
            }
        }

        else if (choice == 4) {
            string fromAcc, toAcc;
            double amount;

            cout << "Enter Sender Account Number: ";
            cin >> fromAcc;
            cout << "Enter Receiver Account Number: ";
            cin >> toAcc;

            int fromIndex = findAccount(accounts, fromAcc);
            int toIndex = findAccount(accounts, toAcc);

            if (fromIndex != -1 && toIndex != -1) {
                cout << "Enter Amount: ";
                cin >> amount;
                accounts[fromIndex].transfer(accounts[toIndex], amount);
            } else {
                cout << "One or both accounts not found.\n";
            }
        }

        else if (choice == 5) {
            string accNum;
            cout << "Enter Account Number: ";
            cin >> accNum;

            int index = findAccount(accounts, accNum);
            if (index != -1) {
                cout << "Current Balance: $" 
                     << accounts[index].getBalance() << "\n";
            } else {
                cout << "Account not found.\n";
            }
        }


        else if (choice == 6) {
            if (accounts.empty()) {
                cout << "No accounts available.\n";
            } else {
                for (const auto &acc : accounts) {
                    acc.displayAccount();
                }
            }
        }

    } while (choice != 7);

    cout << "Exiting program...\n";
    return 0;
}
