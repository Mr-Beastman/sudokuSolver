#include "menu.h"

void Menu::displayTitle() {
    std::cout << "*** Sudoku Solver ***\n";
    std::cout << "---------------------\n";
}

int Menu::displayMainMenu() {
    
    int userInput;
    
    while (true) {
        std::cout << "\n1. Manually Load Puzzle\n";
        std::cout << "2. Load Puzzle from File\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter selection 1, 2 or 3:";
        std::cin >> userInput;

        if (userInput == 1 || userInput == 2 || userInput == 3) {
            break;
        }
        else {
            std::cout << "\nInvalid Input. Please Try again\n";
        }
    }

    

    return userInput;
}

