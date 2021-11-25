#ifndef MATRIX_H
#define MATRIX_H

#include <QTableWidget>
#include <QLineEdit>

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
    matrix(QTableWidget* _net);
    matrix(QTableWidget* _net, mSize _size);

    void build(mSize _size);
    void clear();

    void sum(QLineEdit* e, matrix m1, matrix m2);
    void sub(QLineEdit* e , matrix m1, matrix m2);
    void multiply(QLineEdit* e , matrix m1, matrix m2);
    void multiplyOn(QLineEdit* e , matrix m1, float a);
    void devideOn(QLineEdit* e , matrix m1, float a);


};

#endif // MATRIX_H
