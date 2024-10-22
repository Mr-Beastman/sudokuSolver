#include <QApplication>
#include <QLineEdit>
#include <QDebug>
#include <QString>
#include <QWidget>
#include "solver.h"

solver::solver() {}

void solver::readPuzzle(QWidget *parentWidget)
{
    for(int row = 0;row<9;row++){
        for(int col=0;col<9;col++){

            //calculate input field number
            int inputNumber = row * 9 + col + 1;

            //get input from lineEdit and conver to string
            QString objectName=QString("puzzle_%1").arg(inputNumber);
            QLineEdit *userInput = parentWidget->findChild<QLineEdit *>(objectName);

            if(userInput){
                QString input=userInput->text();

                //if no input store as 0
                if(input.isEmpty()){
                    puzzle[row][col]=0;
                }
                //else convert to int and store
                else{
                    puzzle[row][col]=input.toInt();

                }
            }
        }
    }

    //print for testing
    for(int row = 0;row<9;row++){
        for(int col=0;col<9;col++){
            qDebug()<<"puzzle["<<row<<"]["<<col<<"]="<<puzzle[row][col];
        }
    }
}

void solver::clearPuzzle(QWidget *parentWidget){
    for(int row = 0;row<9;row++){
        for(int col=0;col<9;col++){

            //calculate input field number
            int inputNumber = row * 9 + col + 1;
            QString objectName=QString("puzzle_%1").arg(inputNumber);
            QLineEdit *userInput = parentWidget->findChild<QLineEdit *>(objectName);
            if (userInput) {
                userInput->clear();
            } else {
                // Optionally, handle the case where the QLineEdit wasn't found
                qWarning() << "QLineEdit with objectName" << objectName << "not found.";
            }
        }
    }
}

bool solver::solver::inRow(int row, int number) {
    for(int col = 0;col<9;col++)
        if (puzzle[row][col] == number) {
            return true;
        }
    return false;
}

bool solver::solver::inColumn(int col, int number) {
    for (int row = 0; row < 9; row++)
        if (puzzle[row][col] == number) {
            return true;
        }
    return false;
}

bool solver::solver::inSquare(int startRow, int startColumn, int num) {
    int grid = (startRow / 3) * 3 + (startColumn / 3);
    int gridStartRow = gridStart[grid][0];
    int gridStartColumn = gridStart[grid][1];

    for (int row = 0; row < 3; row++) {
        for (int column=0; column < 3; column++) {
            if (puzzle[gridStartRow+row][gridStartColumn + column] == num) {
                return true;
            }
        }
    }
    return false;
}

bool solver::generateSolution(QWidget *parentWidget) {
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

    //end as no empty cells
    if (!emptyCell) {
        return true;
    }

    //
    for (int num = 1; num <= 9; num++) {
        if (!inRow(row, num) && !inColumn(column, num) && !inSquare(row,column,num)) {
            // Place the number in the puzzle
            puzzle[row][column] = num;

            int inputNumber = row * 9 + column + 1;
            QString objectName = QString("puzzle_%1").arg(inputNumber);
            QLineEdit *lineEdit = parentWidget->findChild<QLineEdit *>(objectName);

            if (lineEdit) {
                lineEdit->setText(QString::number(num));
                qDebug() << "Updated QLineEdit:" << objectName << "with value:" << num;
            } else {
                qWarning() << "QLineEdit with objectName" << objectName << "not found.";
            }

            QApplication::processEvents();

            if (generateSolution(parentWidget)) {
                return true;
            }

            puzzle[row][column] = 0;

            if (lineEdit) {
                lineEdit->clear();
            }
        }
    }
    return false;
}

