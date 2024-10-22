#include <QIntValidator>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "solver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //fixed window side
    setFixedSize(400, 465);

    // Attempt at "validators" to limit inputs to 1-9
    for (int i = 1; i <= 81; i++) {
        QString objectName = QString("puzzle_%1").arg(i); // Corrected object name
        QLineEdit *toCheck = findChild<QLineEdit *>(objectName);

        if (toCheck) {
            QIntValidator *validator = new QIntValidator(1, 9, this);
            toCheck->setValidator(validator);
        }
    }
    //set title
    setWindowTitle("Sudoku Solver");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//solved button functions
void MainWindow::on_solveButton_clicked()
{
    solver data;
    data.readPuzzle(this);
    data.generateSolution(this);
}

//clear button functions
void MainWindow::on_clearButton_clicked()
{
    solver data;
    data.clearPuzzle(this);
}

