#ifndef TRANSACTION_UI_H
#define TRANSACTION_UI_H

#include "../control/TransactionController.h"
#include <string>

class TransactionUI {
private:
    TransactionController& transactionController;

    std::string inputDate();
    double inputAmount();
    std::string inputCategory();
    std::string inputType();
    std::string inputDescription();

public:
    TransactionUI(TransactionController& controller);

    void handleTransactions();
    void addTransaction();
    void editTransaction();
    void deleteTransaction();
    void searchTransactions();
    void sortTransactions();
};

#endif // TRANSACTION_UI_H
