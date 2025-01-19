#include "TransactionController.h"
#include <algorithm>
#include <iostream>

TransactionController::TransactionController() {
    transactions.add(Transaction("T1001", "2024-01-01", 100.0, "Food", "Expense", "Bought lunch"));
    transactions.add(Transaction("T1002", "2024-01-03", 50.0, "Transport", "Expense", "Taxi fare"));
    transactions.add(Transaction("T1003", "2024-01-05", 2000.0, "Salary", "Income", "Monthly salary"));
    transactions.add(Transaction("T1004", "2024-01-07", 75.0, "Entertainment", "Expense", "Movie ticket"));
    transactions.add(Transaction("T1005", "2024-01-10", 30.0, "Utilities", "Expense", "Electric bill"));
    transactions.add(Transaction("T1006", "2024-01-12", 120.0, "Shopping", "Expense", "New clothes"));
}

void TransactionController::addTransaction(const Transaction& transaction) {
    transactions.add(transaction);
    std::cout << "Transaction added successfully!\n";
}

bool TransactionController::updateTransaction(const std::string& id, const std::string& date, double amount,
                                               const std::string& category, const std::string& type, const std::string& description) {
    for (int i = 0; i < transactions.getSize(); i++) {
        if (transactions.get(i).getId() == id) {
            transactions.get(i).setDate(date);
            transactions.get(i).setAmount(amount);
            transactions.get(i).setCategory(category);
            transactions.get(i).setType(type);
            transactions.get(i).setDescription(description);
            std::cout << "Transaction with ID: " << id << " updated successfully.\n";
            return true;
        }
    }
    std::cout << "Transaction with ID: " << id << " not found.\n";
    return false;
}

bool TransactionController::deleteTransaction(const std::string& id) {
    for (int i = 0; i < transactions.getSize(); i++) {
        if (transactions.get(i).getId() == id) {
            transactions.remove(i);
            std::cout << "Transaction deleted successfully!\n";
            return true;
        }
    }
    std::cout << "Transaction with ID: " << id << " not found.\n";
    return false;
}

void TransactionController::displayAllTransactions() const {
    if (transactions.isEmpty()) {
        std::cout << "------------------------\n";
        std::cout << "No transactions available.\n";
        return;
    }

    for (int i = 0; i < transactions.getSize(); i++) {
        std::cout << "------------------------\n";
        std::cout << "Transaction " << i + 1 << ":\n";
        transactions.get(i).displayTransaction();
        std::cout << "------------------------\n";
    }
}

void TransactionController::searchTransactions(const std::string& keyword) const {
    bool found = false;
    for (int i = 0; i < transactions.getSize(); i++) {
        const Transaction& t = transactions.get(i);
        if (t.getCategory().find(keyword) != std::string::npos ||
            t.getDescription().find(keyword) != std::string::npos) {
            t.displayTransaction();
            std::cout << "------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No transactions matching keyword '" << keyword << "' found.\n";
    }
}

void TransactionController::sortTransactions(const std::string& criterion) {
    if (transactions.isEmpty()) {
        std::cout << "No transactions available to sort.\n";
        return;
    }

    for (int i = 0; i < transactions.getSize() - 1; i++) {
        for (int j = 0; j < transactions.getSize() - i - 1; j++) {
            bool swapNeeded = false;

            if (criterion == "date") {
                swapNeeded = transactions.get(j).getDate() > transactions.get(j + 1).getDate();
            } else if (criterion == "amount") {
                swapNeeded = transactions.get(j).getAmount() > transactions.get(j + 1).getAmount(); //BUGG
            } else if (criterion == "category") {
                swapNeeded = transactions.get(j).getCategory() > transactions.get(j + 1).getCategory();//BUGG
            }

            if (swapNeeded) {
                Transaction temp = transactions.get(j);
                transactions.remove(j);
                transactions.addAt(j, transactions.get(j + 1));
                transactions.remove(j + 1);
                transactions.addAt(j + 1, temp);
            }
        }
    }

    std::cout << "Transactions sorted by " << criterion << " successfully.\n";
}
