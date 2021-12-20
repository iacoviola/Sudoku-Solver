#include "solver.h"
#include "ui_solver.h"

Solver::Solver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Solver)
{
    ui->setupUi(this);
}

Solver::~Solver()
{
    delete ui;
}

