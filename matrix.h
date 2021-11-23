#ifndef MATRIX_H
#define MATRIX_H

#include <QTableWidget>

struct mSize{
    mSize() {sizeX = 1; sizeY = 1;}
    mSize(int _sizeX, int _sizeY) {sizeX = _sizeX; sizeY = _sizeY;}

    int sizeX;
    int sizeY;
};

struct matrix{
    mSize size;
    QTableWidget *net;

    matrix();
    matrix(QTableWidget* _net, mSize _size);

    void build(mSize _size);
    void clear();

    void sum(matrix m1, matrix m2);
    void substraction(matrix m1, matrix m2);

};

#endif // MATRIX_H
