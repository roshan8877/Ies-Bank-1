#include <iostream>
using namespace std;

int main() {
    int pin = 1234;  
    int enteredPin;
    int balance;
    int maxBalance = 80000;  
    int attempts = 0;
    bool blocked = false;
    int choice;
    int initialBalance;

    cout << "Enter your current balance (Maximum is 80000): ";
    cin >> balance;

    if (balance > maxBalance) {
        cout << "Error: Balance exceeds the maximum limit of 80000.\n";
        return 1;
    }

    initialBalance = balance;

    while (attempts < 3) {
        cout << "Please enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            cout << "Correct PIN.\n";

            cout << "Enter your choice:\n";
            cout << "1. Balance Enquiry\n";
            cout << "2. Withdrawal\n";
            cout << "3. Mini Statement\n";
            cout << "4. PIN Change\n";
            cin >> choice;

            switch (choice) {
                case 1: 
                    cout << "Your balance is: " << balance << " INR.\n";
                    break;
                case 2: {
                    int withdrawAmount;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmount;

                    if (withdrawAmount <= balance) {
                        balance -= withdrawAmount;
                        cout << "Please take your cash. New balance: " << balance << " INR.\n";
                    } else {
                        cout << "Insufficient balance!\n";
                    }
                    break;
                }
                case 3:
                    cout << "Mini statement:\n";
                    cout << "Your initial balance was: " << initialBalance << " INR.\n";
                    cout << "Your current balance is: " << balance << " INR.\n";
                    break;
                case 4: {
                    // PIN Change
                    int newPin;
                    cout << "Enter new PIN: ";
                    cin >> newPin;
                    pin = newPin;
                    cout << "PIN changed successfully.\n";
                    break;
                }
                default:
                    cout << "Invalid choice!\n";
            }

            break; 
        } else {
            attempts++;
            if (attempts == 3) {
                blocked = true;
                cout << "Your account is blocked due to 3 incorrect attempts.\n";
            } else {
                cout << "Wrong PIN. Try again.\n";
            }
        }
    }

    return 0;
}