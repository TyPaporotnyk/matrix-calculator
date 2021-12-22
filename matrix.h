#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

private:
    double **matrix;
    int width;
    int height;

public:

    Matrix();
    Matrix(int _height, int _width);
    Matrix(int _height, int _width, double **_matrix);

    double** getMatrix();
    int getWidth();
    int getHeight();

    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;

    void transpose();

    void build(int width, int height);
};

#endif // MATRIX_H
