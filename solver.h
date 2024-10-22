#ifndef SOLVER_H
#define SOLVER_H

#include "qwidget.h"

class solver
{
    int puzzle[9][9];
    int gridStart[9][2] = {
        {0,0}, {0,3}, {0,6},
        {3,0}, {3,3}, {3,6},
        {6,0}, {6,3}, {6,6}
    };

public:
    solver();

    void readPuzzle(QWidget *parentWidget);
    void clearPuzzle(QWidget *parentWidget);
    bool inRow(int row, int number);
    bool inColumn(int col, int number);
    bool inSquare(int startRow, int startColumn, int num);
    bool generateSolution(QWidget *parentWidget);
};

#endif // SOLVERLOGIC_H
