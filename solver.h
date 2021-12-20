#ifndef SOLVER_H
#define SOLVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Solver; }
QT_END_NAMESPACE

class Solver : public QMainWindow
{
    Q_OBJECT

public:
    Solver(QWidget *parent = nullptr);
    ~Solver();

private:
    Ui::Solver *ui;
};
#endif // SOLVER_H
