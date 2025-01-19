#include "TransactionUI.h"
#include <iostream>
#include <regex>
#include <limits>




TransactionUI::TransactionUI(TransactionController& controller) : transactionController(controller) {}

std::string TransactionUI::inputDate() {
    std::string date;
    std::regex datePattern("\\d{4}-\\d{2}-\\d{2}");
    while (true) {
        std::cout << "Enter date (YYYY-MM-DD): ";
        std::cin >> date;
        if (std::regex_match(date, datePattern)) {
            break;
        } else {
            std::cout << RED << "Invalid date format. Please try again.\n" << RESET;
        }
    }
    return date;
}

double TransactionUI::inputAmount() {
    double amount;
    while (true) {
        std::cout << "Enter amount: ";
        std::cin >> amount;
        if (std::cin.fail() || amount <= 0) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << RED << "Invalid amount. Please enter a positive number.\n" << RESET;
        } else {
            break;
        }
    }
    return amount;
}

std::string TransactionUI::inputCategory() {
    std::string category;
    while (true) {
        std::cout << "Enter category: ";
        std::cin >> category;
        if (!category.empty()) {
            break;
        } else {
            std::cout << RED << "Category cannot be empty. Please try again.\n" << RESET;
        }
    }
    return category;
}

std::string TransactionUI::inputType() {
    std::string type;
    while (true) {
        std::cout << "Enter type (Income/Expense): ";
        std::cin >> type;
        if (type == "Income" || type == "Expense") {
            break;
        } else {
            std::cout << RED << "Invalid type. Please enter 'Income' or 'Expense'.\n" << RESET;
        }
    }
    return type;
}

std::string TransactionUI::inputDescription() {
    std::string description;
    while (true) {
        std::cout << "Enter description: ";
        std::cin.ignore(); // Ignore leftover newline
        std::getline(std::cin, description);
        if (!description.empty()) {
            break;
        } else {
            std::cout << RED << "Description cannot be empty. Please try again.\n" << RESET;
        }
    }
    return description;
}

void TransactionUI::handleTransactions() {
    int choice;
    do {
        std::cout << "\n=============================\n";
        std::cout << "  Transaction Management\n";
        std::cout << "=============================\n";
        std::cout << "1. Add Transaction\n";
        std::cout << "2. Edit Transaction\n";
        std::cout << "3. Delete Transaction\n";
        std::cout << "4. Search Transactions\n";
        std::cout << "5. Sort Transactions\n";
        std::cout << "6. Display All Transactions\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addTransaction(); break;
            case 2: editTransaction(); break;
            case 3: deleteTransaction(); break;
            case 4: searchTransactions(); break;
            case 5: sortTransactions(); break;
            case 6: transactionController.displayAllTransactions(); break;
            case 7: std::cout << "Exiting Transaction Management.\n"; break;
            default: std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
        }
    } while (choice != 7);
}

void TransactionUI::addTransaction() {
    std::string date = inputDate();
    double amount = inputAmount();
    std::string category = inputCategory();
    std::string type = inputType();
    std::string description = inputDescription();

    static int idCounter = 1000;
    std::string id = "T" + std::to_string(idCounter++);
    Transaction transaction(id, date, amount, category, type, description);
    transactionController.addTransaction(transaction);
}

void TransactionUI::editTransaction() {
    std::string id;
    std::cout << "Enter Transaction ID to edit: ";
    std::cin >> id;

    std::string date = inputDate();
    double amount = inputAmount();
    std::string category = inputCategory();
    std::string type = inputType();
    std::string description = inputDescription();

    if (!transactionController.updateTransaction(id, date, amount, category, type, description)) {
        std::cout << RED << "Transaction with ID " << id << " not found.\n" << RESET;
    }
}

void TransactionUI::deleteTransaction() {
    std::string id;
    std::cout << "Enter Transaction ID to delete: ";
    std::cin >> id;

    if (!transactionController.deleteTransaction(id)) {
        std::cout << RED << "Transaction with ID " << id << " not found.\n" << RESET;
    }
}

void TransactionUI::searchTransactions() {
    std::string keyword;
    std::cout << "Enter keyword to search: ";
    std::cin >> keyword;
    transactionController.searchTransactions(keyword);
}

void TransactionUI::sortTransactions() {
    std::string criterion;
    std::cout << "Enter criterion to sort (date/amount/category): ";
    std::cin >> criterion;
    transactionController.sortTransactions(criterion);
}
