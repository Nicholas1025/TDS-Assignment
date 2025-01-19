#include "Transaction.h"
#include <iostream>

// Default constructor
Transaction::Transaction()
    : id("T0000"), date("1970-01-01"), amount(0.0),
      category("Undefined"), type("Undefined"), description("Undefined") {}

// Parameterized constructor
Transaction::Transaction(const std::string& id, const std::string& date, double amount,
                         const std::string& category, const std::string& type, const std::string& description)
    : id(id), date(date), amount(amount), category(category), type(type), description(description) {}

std::string Transaction::getId() const {
    return id;
}

std::string Transaction::getDate() const {
    return date;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getCategory() const {
    return category;
}

std::string Transaction::getType() const {
    return type;
}

std::string Transaction::getDescription() const {
    return description;
}

void Transaction::setDate(const std::string& date) {
    this->date = date;
}

void Transaction::setAmount(double amount) {
    this->amount = amount;
}

void Transaction::setCategory(const std::string& category) {
    this->category = category;
}

void Transaction::setType(const std::string& type) {
    this->type = type;
}

void Transaction::setDescription(const std::string& description) {
    this->description = description;
}

void Transaction::displayTransaction() const {
    std::cout << "ID: " << id << "\n"
              << "Date: " << date << "\n"
              << "Amount: " << amount << "\n"
              << "Category: " << category << "\n"
              << "Type: " << type << "\n"
              << "Description: " << description << "\n";
}
