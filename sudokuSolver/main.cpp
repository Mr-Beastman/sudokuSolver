// sudokuSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "solver.h"
#include "menu.h"

int main()
{
    Solver sudoku;
    Menu menu;
    int userInput;

    menu.displayTitle();

    while (true) {
        userInput = menu.displayMainMenu();

        if (userInput == 1) {
            sudoku.enterPuzzle();
        }
        else if (userInput == 2) {
            sudoku.readPuzzleFromFile();
        }
        else if (userInput == 3) {
            break;
        }

        std::cout << "\n----------------\n";
        std::cout << "\nPuzzle to Solve:\n";
        sudoku.displayPuzzle();

        sudoku.generateSolution();

        std::cout << "\nPuzzle Solution:\n";
        sudoku.displayPuzzle();
        std::cout << "\n----------------\n";
    }
}

