#include <iostream>
#include "boundary/TransactionUI.h"
#include "boundary/BudgetUI.h"
#include "control/TransactionController.h"
#include "control/BudgetController.h"
#include "utility/Utility.h"
#include <cstdlib>

// Function prototypes
void displayMainMenu();

int main() {
    TransactionController transactionController;
    BudgetController budgetController;

    TransactionUI transactionUI(transactionController);
    BudgetUI budgetUI(budgetController);

    int choice;

    do {
        clearScreen(); // Clear the screen before displaying the main menu
        displayMainMenu();
        std::cin >> choice;

        clearScreen(); // Clear the screen before handling user choice
        switch (choice) {
        case 1:
            transactionUI.handleTransactions();
            break;
        case 2:
            budgetUI.handleBudgets();
            break;
        case 3:
            std::cout << "User Management (Placeholder)\n";
            break;
        case 4:
            std::cout << "Report Generation (Placeholder)\n";
            break;
        case 5:
            std::cout << "\033[32mExiting the system. Goodbye!\033[0m\n";
            break;
        default:
            std::cout << "\033[31mInvalid choice. Please try again.\033[0m\n";
        }
    } while (choice != 5);

    return 0;
}

// Display the main menu
void displayMainMenu() {
    std::cout << "                  ____     ____\n";
    std::cout << "                /'    |   |    \\\n";
    std::cout << "              /    /  |   | \\   \\\n";
    std::cout << "            /    / |  |   |  \\   \\\n";
    std::cout << "           (   /   |  \"\"\"\"   |\\   \\       \n";
    std::cout << "           | /   / /^\    /^\  \\  _|          \n";
    std::cout << "            ~   | |   |  |   | | ~\n";
    std::cout << "                | |__O|__|O__| |\n";
    std::cout << "              /~~      \\/     ~~\\\n";
    std::cout << "             /   (      |      )  \\\n";
    std::cout << "       _--_  /,   \\____/^\\" << "\\___/'   \\  _--_\n";
    std::cout << "     /~    ~\\ / -____-|_|_|-____-\\" << "/~    ~\\\n";
    std::cout << "   /________|___/~~~~\\___/~~~~\\ __|________\\\n";
    std::cout << "-~~~          ^ |     |   |     |  -     :  ~~~~~:~-_     ___-----~~~~~~~~|\n";
    std::cout << "/               `^-^-^'   `^-^-^'                  :  ~\\ /'   ____/--------|\n";
    std::cout << "    --                                            ;   |/~~~------~~~~~~~~~|\n";
    std::cout << "                                   :              :    |----------/--------|\n";
    std::cout << "                   ,                           ;    .  |---\\\\--------------|\n";
    std::cout << "    -                          .                  : : |______________-__|\n";
    std::cout << "              ,                 ,                :   /'~----___________|\n";
    std::cout << " \\\\\\        ^                          ,, ;; ;; ;._-~\n";
    std::cout << "~~-----____________________________________----~~~\n";
     std::cout << "\033[36m=============================\033[0m\n";
    std::cout << "\033[36m  Personal Finance Tracker\n";
    std::cout << "=============================\033[0m\n";
    std::cout << "1. Manage Transactions\n";
    std::cout << "2. Manage Budgets\n";
    std::cout << "3. Manage Users (Placeholder)\n";
    std::cout << "4. Generate Reports (Placeholder)\n";
    std::cout << "5. Exit\n";
    std::cout << "=============================\n";
    std::cout << "Enter your choice: ";
}


