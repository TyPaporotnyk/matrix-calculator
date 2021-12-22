#ifndef LINKER_H
#define LINKER_H

#include "matrix.h"
#include <QTableWidget>

class Linker{
public:
    void display(Matrix& m, QTableWidget *net);
    void netToMatrix(QTableWidget *net, Matrix& m);
    double stringToNum(QString str);
};

#endif // LINKER_H
