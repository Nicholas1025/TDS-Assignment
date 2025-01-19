#include "BudgetController.h"
#include <iostream>

int BudgetController::idCounter = 1000;

BudgetController::BudgetController() {

}

std::string BudgetController::generateBudgetId() {
    idCounter++;
    return "B" + std::to_string(idCounter);
}


void BudgetController::addBudget(const std::string& category, double amount, const std::string& startDate, const std::string& endDate) {
    std::string id = generateBudgetId();
    Budget newBudget(id, category, amount, startDate, endDate);
    budgets.add(newBudget);
    std::cout << "Budget added successfully with ID: " << id << "\n";
}

bool BudgetController::deleteBudget(const std::string& id) {
    for (int i = 0; i < budgets.getSize(); i++) {
        if (budgets.get(i).getId() == id) {
            budgets.remove(i);
            std::cout << "Budget with ID: " << id << " deleted successfully.\n";
            return true;
        }
    }
    std::cout << "Budget with ID: " << id << " not found.\n";
    return false;
}

bool BudgetController::updateBudget(const std::string& id, const std::string& category, double amount, const std::string& startDate, const std::string& endDate) {
    for (int i = 0; i < budgets.getSize(); i++) {
        if (budgets.get(i).getId() == id) {
            budgets.get(i).setCategory(category);
            budgets.get(i).setAmount(amount);
            budgets.get(i).setStartDate(startDate);
            budgets.get(i).setEndDate(endDate);
            std::cout << "Budget with ID: " << id << " updated successfully.\n";
            return true;
        }
    }
    std::cout << "Budget with ID: " << id << " not found.\n";
    return false;
}

Budget* BudgetController::findBudgetById(const std::string& id) {
    for (int i = 0; i < budgets.getSize(); i++) {
        if (budgets.get(i).getId() == id) {
            return &budgets.get(i);
        }
    }
    return nullptr;
}

void BudgetController::displayAllBudgets() const {
    if (budgets.isEmpty()) {
        std::cout << "No budgets available.\n";
        return;
    }

    for (int i = 0; i < budgets.getSize(); i++) {
        budgets.get(i).displayBudget();
        std::cout << "----------------------\n";
    }
}
