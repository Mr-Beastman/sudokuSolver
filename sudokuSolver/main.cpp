// sudokuSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "solver.h"

int main()
{
    Solver sudoku;


    sudoku.enterPuzzle();
    //sudoku.readPuzzleFromFile();

    std::cout << "Puzzle to Solve:\n";
    sudoku.displayPuzzle();
    sudoku.generateSolution();

    std::cout << "\nPuzzle Solution:\n";
    sudoku.displayPuzzle();
}

