#ifndef TRANSACTION_CONTROLLER_H
#define TRANSACTION_CONTROLLER_H

#include "../adt/LinkedList.h"
#include "../entity/Transaction.h"
#include <string>
#define RED "\033[31m"
#define RESET "\033[0m"
class TransactionController {
private:
    LinkedList<Transaction> transactions;

public:
    TransactionController();

    void addTransaction(const Transaction& transaction);
    bool updateTransaction(const std::string& id, const std::string& date, double amount,
                           const std::string& category, const std::string& type, const std::string& description);
    bool deleteTransaction(const std::string& id);
    void displayAllTransactions() const;
    void searchTransactions(const std::string& keyword) const;
    void sortTransactions(const std::string& criterion);
};

#endif // TRANSACTION_CONTROLLER_H
