#ifndef BUDGETUI_H
#define BUDGETUI_H

#include "../control/BudgetController.h"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
class BudgetUI {
private:
    BudgetController& budgetController;

    std::string inputValidId();
    double inputValidAmount();
    std::string inputValidDate(const std::string& prompt);
    std::string inputValidCategory();

public:
    BudgetUI(BudgetController& controller);

    void handleBudgets();
    void addBudgetUI();
    void deleteBudgetUI();
    void updateBudgetUI();
    void displayAllBudgetsUI();
};

#endif // BUDGETUI_H
