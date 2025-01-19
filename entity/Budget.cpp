#include "Budget.h"
#include <iostream>

// 默认构造函数
Budget::Budget() : id(""), category(""), amount(0.0), startDate(""), endDate("") {}

// 参数化构造函数
Budget::Budget(const std::string& id, const std::string& category, double amount, const std::string& startDate, const std::string& endDate)
    : id(id), category(category), amount(amount), startDate(startDate), endDate(endDate) {}

// Getters
std::string Budget::getId() const {
    return id;
}

std::string Budget::getCategory() const {
    return category;
}

double Budget::getAmount() const {
    return amount;
}

std::string Budget::getStartDate() const {
    return startDate;
}

std::string Budget::getEndDate() const {
    return endDate;
}

// Setters
void Budget::setCategory(const std::string& category) {
    this->category = category;
}

void Budget::setAmount(double amount) {
    this->amount = amount;
}

void Budget::setStartDate(const std::string& startDate) {
    this->startDate = startDate;
}

void Budget::setEndDate(const std::string& endDate) {
    this->endDate = endDate;
}

void Budget::displayBudget() const {
    std::cout << "Budget ID: " << id << "\n"
              << "Category: " << category << "\n"
              << "Amount: RM " << amount << "\n"
              << "Start Date: " << startDate << "\n"
              << "End Date: " << endDate << "\n";
}
