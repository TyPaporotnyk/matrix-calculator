#ifndef MATRIX_H
#define MATRIX_H

class Matrix {

private:
    double **matrix;
    int width;
    int height;

    double findDet(double **a, int n);
    void clearMemory(double **arr, int n);

public:
    ~Matrix();
    Matrix();
    Matrix(int _height, int _width);
    Matrix(int _height, int _width, double **_matrix);

    double** getMatrix();
    int getWidth();
    int getHeight();

    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;

//    Matrix operator+(double num);
//    Matrix operator-(double num);
    Matrix operator*(double num);
    Matrix operator/(double num);

    void transpose();
    double det();

    void build(int width, int height);
    void build(Matrix m);
};

#endif // MATRIX_H
