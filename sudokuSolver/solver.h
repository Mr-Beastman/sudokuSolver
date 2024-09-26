#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

class Solver {
    int puzzle[9][9];
    std::string puzzleFile = "puzzles.txt";
    int grids[9][2] = { 
        {1,1}, {1,4}, {1,7},
        {4,1}, {4,4}, {4,7},
        {7,1}, {7,4}, {7,7}
    };

public:
    
    //function to display array in 9x9 format
    void displayPuzzle();

    //load puzzle to array from file
    void readPuzzleFromFile();

    //manual entering of a puzzle as string
    void enterPuzzle();

    bool inRow(int row,int number);
    bool inColumn(int col, int number);
    bool inSquare(int startRow, int startColumn, int num);
    bool validInput();


    bool generateSolution();
};

