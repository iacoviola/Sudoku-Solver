#include "solver.h"
#include "ui_solver.h"
#include "sudoku.h"

QLineEdit *cells[81];
QHBoxLayout *layouts[9];

Solver::Solver(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::Solver)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setColor(QPalette::Base, Qt::lightGray);
    for(int j = 0; j < 9; j++){
        layouts[j] = new QHBoxLayout();
        layouts[j]->setSpacing(0);
        ui->verticalLayout->addLayout(layouts[j]);
    }
    int j = 0;
    for(int i = 0; i < 81; i++){
        cells[i] = new QLineEdit();
        cells[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        cells[i]->setAlignment(Qt::AlignCenter);
        cells[i]->setFont(QFont("AppleSystemUIFont", 18));
        if(j % 2 == 0)
            cells[i]->setPalette(palette);
        layouts[j]->addWidget(cells[i]);
        if((i + 1) % 9 == 0)
            j++;
    }

    connect(ui->Solve, SIGNAL(released()), this, SLOT(SolveButtonPressed()));

}

Solver::~Solver()
{
    delete ui;
}

void Solver::SolveButtonPressed(){
    qInfo() << "C++ Style Info Message";
    for(int i = 0; i < 81; i++){
        qInfo() << "C++ Style Info Message Inside";
        if(cells[i]->text().isEmpty())
            grid[i / N][i % N] = 0;
        else
            grid[i / N][i % N] = cells[i]->text().toInt();
    }
    if(solveSudoku(grid)){
        for(int i = 0; i < 81; i++){
            cells[i]->setText(QString::number(grid[i / N][i % N]));
            cells[i]->setReadOnly(true);
        }
    }
    else
        QMessageBox::warning(this, "Error", "Can't find any solutions");
}
