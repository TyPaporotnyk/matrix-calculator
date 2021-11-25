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

    void baseOp(QLineEdit* e, matrix m1, matrix m2, float(*f)(float a, float b));
    void arithmetikOp(QLineEdit* e , matrix m1, float a, float(*f)(float a, float b));
    void multiply(QLineEdit* e , matrix m1, matrix m2);
    void determinant(QLineEdit* e);
    void clearMemory(float** a, int n);
    float findDet(float** a, int n);
};

float sum(float a, float b);
float sub(float a, float b);
float multi(float a, float b);
float divide(float a, float b);

#endif // MATRIX_H
