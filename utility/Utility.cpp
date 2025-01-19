#include "Utility.h"
#include <cstdlib>
#include <regex>
#include <iostream>

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux/macOS
#endif
}

// Example validation functions
bool isValidDate(const std::string& date) {
    std::regex datePattern("\\d{4}-\\d{2}-\\d{2}");
    return std::regex_match(date, datePattern);
}

bool isValidAmount(double amount) {
    return amount > 0;
}
