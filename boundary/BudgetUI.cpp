#include "BudgetUI.h"
#include <iostream>
#include <regex>
#include <limits>

using namespace std;

#define RESET "\033[0m"
#define RED "\033[31m"

BudgetUI::BudgetUI(BudgetController& controller) : budgetController(controller) {}

void BudgetUI::handleBudgets() {
    int choice;
    do {
        cout << "\n===== Budget Management =====\n";
        cout << "1. Add Budget\n";
        cout << "2. Delete Budget\n";
        cout << "3. Update Budget\n";
        cout << "4. Display All Budgets\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBudgetUI();
            break;
        case 2:
            deleteBudgetUI();
            break;
        case 3:
            updateBudgetUI();
            break;
        case 4:
            displayAllBudgetsUI();
            break;
        case 5:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }
    } while (choice != 5);
}

void BudgetUI::addBudgetUI() {
    cout << "=== Add Budget ===\n";
    string category = inputValidCategory();
    double amount = inputValidAmount();
    string startDate = inputValidDate("Enter start date (YYYY-MM-DD): ");
    string endDate = inputValidDate("Enter end date (YYYY-MM-DD): ");

    budgetController.addBudget(category, amount, startDate, endDate);
}

void BudgetUI::deleteBudgetUI() {
    cout << "=== Delete Budget ===\n";
    string id = inputValidId();

    if (!budgetController.deleteBudget(id)) {
        cout << RED << "Failed to delete budget. Budget ID not found.\n" << RESET;
    }
}

void BudgetUI::updateBudgetUI() {
    cout << "=== Update Budget ===\n";
    string id = inputValidId();
    string category = inputValidCategory();
    double amount = inputValidAmount();
    string startDate = inputValidDate("Enter new start date (YYYY-MM-DD): ");
    string endDate = inputValidDate("Enter new end date (YYYY-MM-DD): ");

    if (!budgetController.updateBudget(id, category, amount, startDate, endDate)) {
        cout << RED << "Failed to update budget. Budget ID not found.\n" << RESET;
    }
}

void BudgetUI::displayAllBudgetsUI() {
    cout << "=== All Budgets ===\n";
    budgetController.displayAllBudgets();
}

string BudgetUI::inputValidId() {
    string id;
    regex idPattern("^B\\d{4}$");
    do {
        cout << "Enter Budget ID (e.g., B1001): ";
        cin >> id;
        if (!regex_match(id, idPattern)) {
            cout << RED << "Invalid ID format. Please try again.\n" << RESET;
        }
    } while (!regex_match(id, idPattern));
    return id;
}

double BudgetUI::inputValidAmount() {
    double amount;
    do {
        cout << "Enter amount (positive number): ";
        cin >> amount;
        if (cin.fail() || amount <= 0) {
            cout << RED << "Invalid amount. Please enter a positive number.\n" << RESET;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (amount <= 0);
    return amount;
}

string BudgetUI::inputValidDate(const string& prompt) {
    string date;
    regex datePattern("^\\d{4}-\\d{2}-\\d{2}$");
    do {
        cout << prompt;
        cin >> date;
        if (!regex_match(date, datePattern)) {
            cout << RED << "Invalid date format. Please try again (YYYY-MM-DD).\n" << RESET;
        }
    } while (!regex_match(date, datePattern));
    return date;
}

string BudgetUI::inputValidCategory() {
    string category;
    cout << "Enter category (e.g., Food, Transport, Shopping): ";
    cin >> category;
    return category;
}
