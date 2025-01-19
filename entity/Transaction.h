#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string id;          // Transaction ID
    std::string date;        // Date of the transaction
    double amount;           // Amount of the transaction
    std::string category;    // Category (e.g., Food, Transport)
    std::string type;        // Transaction type (Income or Expense)
    std::string description; // Description of the transaction

public:
    Transaction(); // Default constructor
    Transaction(const std::string& id, const std::string& date, double amount,
                const std::string& category, const std::string& type, const std::string& description);

    std::string getId() const;
    std::string getDate() const;
    double getAmount() const;
    std::string getCategory() const;
    std::string getType() const;
    std::string getDescription() const;

    void setDate(const std::string& date);
    void setAmount(double amount);
    void setCategory(const std::string& category);
    void setType(const std::string& type);
    void setDescription(const std::string& description);

    void displayTransaction() const;
};

#endif // TRANSACTION_H
