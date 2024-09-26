#include "solver.h"



void Solver::displayPuzzle() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << puzzle[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void Solver::readPuzzleFromFile() {
    std::string puzzleString;
    std::ifstream loadPuzzle(puzzleFile);
    int number = 0;

    while (std::getline(loadPuzzle, puzzleString)) {
        if (puzzleString == "puzzleOne") {
            std::getline(loadPuzzle, puzzleString);
            break;
        }
    }

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            puzzle[row][col] = puzzleString[number++]-'0';
        }
    }

    loadPuzzle.close();
}

void Solver::enterPuzzle() {
    std::string puzzleString;
    int number = 0;

    std::cout << "\nEnter Puzzle form left to right starting on stop row no spaces (blank=0)\n";
    std::cin >> puzzleString;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            puzzle[row][col] = puzzleString[number++] - '0';
        }
    }
}

bool Solver::inRow(int row, int number) {
    for(int col = 0;col<9;col++)
        if (puzzle[row][col] == number) {
            return true;
        }
    return false;
}

bool Solver::inColumn(int col, int number) {
    for (int row = 0; row < 9; row++)
        if (puzzle[row][col] == number) {
            return true;
        }
    return false;
}

bool Solver::inSquare(int startRow, int startColumn, int num) {
    for (int row = 0; row < 3; row++) {
        for (int column=0; column < 3; column++) {
            if (puzzle[row + startRow][column + startColumn] == num) {
                return true;
            }
        }
    }
    return false;
}

bool Solver::validInput() {
    for (int i = 0; i < 9; i++) {
        if (inRow(i, 1)&&inColumn(i,1)) {
            std::cout << "\nFound\n";
            std::cout << i << '\n';
        }
    }
    return true;
}

bool Solver::generateSolution() {

    int row, column;

    bool emptyCell = false;

    for (row = 0; row < 9; row++) {
        for (column = 0; column < 9; column++) {
            if (puzzle[row][column] == 0) {
                emptyCell = true;
                break;
            }
        }
        if (emptyCell) {
            break;
        }
    }

    if (!emptyCell) {
        return true;
    }
     
    for (int num = 1; num <= 9; num++) {
        if (!inRow(row, num) && !inColumn(column, num) && !inSquare(row-row%3,column-column%3,num)) {
            puzzle[row][column]=num;

            if (generateSolution())
                return true;

            puzzle[row][column] = 0;
        }
    }
    return false;
}