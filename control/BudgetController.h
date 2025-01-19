#ifndef BUDGETCONTROLLER_H
#define BUDGETCONTROLLER_H

#include "../adt/LinkedList.h"
#include "../entity/Budget.h"
#include <string>

class BudgetController {
private:
    LinkedList<Budget> budgets;
    static int idCounter;

    std::string generateBudgetId();

public:
    BudgetController();

    void addBudget(const std::string& category, double amount, const std::string& startDate, const std::string& endDate);
    bool deleteBudget(const std::string& id);
    bool updateBudget(const std::string& id, const std::string& category, double amount, const std::string& startDate, const std::string& endDate);
    Budget* findBudgetById(const std::string& id);
    void displayAllBudgets() const;
};

#endif // BUDGETCONTROLLER_H
