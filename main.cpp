#include <iostream>
#include <vector>
#include "expense.h"

using namespace std;

vector<Expense> expenses;
int nextId = 1;

void addExpense(vector <Expense>& expenses){
    cout << "========== ADD EXPENSE ==========\n";

    string description, category;
    double amount;

    cin.ignore(); // buffer 

    cout << "Enter the description :: \n";
    getline(cin, description);

    cout << "Enter the amount :: \n";
    cin >> amount;

    cin.ignore(); // buffer 

    cout << "Enter the category :: \n";
    getline(cin, category);

    Expense expense(nextId, description, amount, category);

    expenses.push_back(expense);
    nextId++;

    cout << "Expense added successfully!\n";
    cout << "Expense ID -> " << expense.getId() << endl;
}

void showAllExpenses(const vector<Expense>& expenses) {

    if (expenses.empty()){
        cout << "No Expenses\n";
        return;
    }

    cout << "========== ALL EXPENSES ==========\n";
    for (const Expense& expense : expenses){
        cout << "ID :: " << expense.getId() << endl;
        cout << "Description :: " << expense.getDescription() << endl;
        cout << "Amount :: $" << expense.getAmount() << endl;
        cout << "Category :: " << expense.getCategory() << endl;
        cout << "===================================\n";
    }

}

void removeExpense(vector<Expense>& expenses) {

    int id;

    cout << "========== REMOVE EXPENSE ==========\n";
    cout << "Enter the ID of the expense: ";
    cin >> id;

    if (expenses.empty()) {
        cout << "No Expenses\n";
        return;
    }

    for (int i = 0; i < expenses.size(); i++) {

        if (id == expenses[i].getId()) {

            expenses.erase(expenses.begin() + i); // nao recebe o objeto, aponta para o primeiro elemento e depois pula até i

            cout << "Expense removed successfully!\n";
            return;
        }
    }

    cout << "Expense Not Found!\n";
}

void showTotal(const vector<Expense>& expenses){
    if (expenses.empty()) {
        cout << "No Expenses\n";
        return;
    }
    int counter = 0;
    double totalAmount = 0;
    cout << "========== TOTAL EXPENSES ===========";

    for (const Expense& expense : expenses){
        counter++;
        totalAmount += expense.getAmount();
    }

    cout << "Total Expenses :: " << counter << endl;
    // cout << "Total Expenses :: " << expenses.size() << endl;
    cout << "Total Amount :: $" << totalAmount << endl;

}


int main() {

    int option;

    do {

        cout << "\n==============================\n";
        cout << "       EXPENSE TRACKER\n";
        cout << "==============================\n";

        cout << "1 - Add Expense\n";
        cout << "2 - Show All Expenses\n";
        cout << "3 - Remove Expense\n";
        cout << "4 - Show Total\n";
        cout << "5 - Exit\n";

        cout << "==============================\n";
        cout << "Choose an option: ";

        cin >> option;

        switch (option) {

        case 1:
            addExpense(expenses);
            break;

        case 2:
            showAllExpenses(expenses);
            break;

        case 3:
            removeExpense(expenses);
            break;

        case 4:
            showTotal(expenses);
            break;

        case 5:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (option != 5);

    return 0;
}
