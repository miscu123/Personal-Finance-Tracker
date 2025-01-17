/*Creare proeict OOP despre Personal Finance Tracker
1. Define Requirements: 
income and expenses
view transaction history
summaries (monthly, yearly)
categorize transactions (groceries, entertainment)
2. Identify Classes and their responsibilities:
2.1. transactions: attributes: amount, date, type, category, description
methods: getters and setters, display details
2.2. account: attributes: account name, balance, list of transactions
methods: add transaction, get balance, view transactions
3. Design Class Interactions:
account: contains multiple transaction objects
main application class to manage user input and interface
4. Plan the User interface
5. Outline Data Storage:
consider how you'll store data (in-memmory for simplicity OR use files)
if using files, think about how to read/write transactions
6. Implementation Steps:
6.1. Create Classes (transactions, account, budget)
6.2. Implement methods: add necessary methods to handle transactions and accounts
6.3. Build Main: vreate a main menu for user interaction, looping untile the user chooses to exit
6.4. Hnadle User Input: Validate and process user inputs for adding/viewing transactions
7. Testing:
test each class and method individually
validate that transactions are correctly added and summaries are accurate
8. Iteration and Expansion
Once the core features are implemented, consider expanding the app
9.Documentation:
Write documentation for your classes and how to use the app
Include examples of input and eexpected output
*/

#include "Classes.h"
#include <iostream>
using namespace std;

int main() {
    Account account1;
    account1.AccountRead();
    char option;

    do {
        cout << "Do you wish to add a transaction? (y/n): ";
        cin >> option;
        if (option == 'y' || option == 'Y') {
            Transaction transaction;
            transaction.read();
            account1.AddTransaction(transaction);
        }
    } while (option == 'y' || option == 'Y');

    cout << "Account details:" << endl;
    account1.AccountDetails();

    return 0;
}
