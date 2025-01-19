#ifndef BUDGET_H
#define BUDGET_H

#include <string>

class Budget {
private:
    std::string id;
    std::string category;
    double amount;
    std::string startDate;
    std::string endDate;

public:

    Budget();
    Budget(const std::string& id, const std::string& category, double amount, const std::string& startDate, const std::string& endDate);


    std::string getId() const;
    std::string getCategory() const;
    double getAmount() const;
    std::string getStartDate() const;
    std::string getEndDate() const;


    void setCategory(const std::string& category);
    void setAmount(double amount);
    void setStartDate(const std::string& startDate);
    void setEndDate(const std::string& endDate);


    void displayBudget() const;
};

#endif // BUDGET_H
