#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

class Solver {
    int puzzle[9][9];
    std::string puzzleFile = "puzzles.txt";
    int gridStart[9][2] = { 
        {0,0}, {0,3}, {0,6},
        {3,0}, {3,3}, {3,6},
        {6,0}, {6,3}, {6,6}
    };

public:
    
    //function to display array in 9x9 format
    void displayPuzzle();

    //load puzzle to array from file
    void readPuzzleFromFile();

    //manual entering of a puzzle as string
    void enterPuzzle();

    //check if number exists in row
    bool inRow(int row,int number);

    //check if number exists in column
    bool inColumn(int col, int number);

    //check if number exists in square (3x3)
    bool inSquare(int startRow, int startColumn, int num);


    bool generateSolution();
};

