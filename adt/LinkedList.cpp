#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

class Transaction {
private:
    std::string id;
    std::string date;
    double amount;
    std::string category;
    std::string type;
    std::string description;


public:
    // Default constructor
    Transaction() : id(""), date(""), amount(0.0), category(""), type(""), description("") {}

    // Parameterized constructor
    Transaction(const std::string& id, const std::string& date, double amount,
                const std::string& category, const std::string& type, const std::string& description);

    // Getters and setters
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

    // Display
    void displayTransaction() const;
};

#endif // TRANSACTION_H
