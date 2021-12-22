#include "matrix.h"
#include <stdexcept>
#include <math.h>

Matrix::~Matrix()
{

}

Matrix::Matrix()
{
    Matrix(1, 1);
}

Matrix::Matrix(int _height, int _width) : height(_height), width(_width)
{
    build(width, height);
}

Matrix::Matrix(int _height, int _width, double **_matrix)
{
    matrix = new double*[height];
    for(int i = 0; i < height; i++)
    {
        matrix[i] = new double[width];
        for(int j = 0; j < width; j++)
        {
            matrix[i][j] = _matrix[i][j];
        }
    }
}

void Matrix::build(int width, int height)
{
    this->width = width;
    this->height = height;

    matrix = new double*[height];
    for(int i = 0; i < height; i++)
    {
        matrix[i] = new double[width];
        for(int j = 0; j < width; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void Matrix::build(Matrix m)
{
    width = m.width;
    height = m.height;

    matrix = new double*[height];
    for(int i = 0; i < height; i++)
    {
        matrix[i] = new double[width];
        for(int j = 0; j < width; j++)
        {
            matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix Matrix::operator+(const Matrix& m) const
{
    if(height != m.height || width != m.width)
        throw std::overflow_error("Матриці різних розмірів");

    Matrix mtr(height, width);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            mtr.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }

    return mtr;
}

Matrix Matrix::operator-(const Matrix& m) const
{
    if(height != m.height || width != m.width)
        throw std::overflow_error("Матриці різних розмірів");

    Matrix mtr(height, width);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            mtr.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }

    return mtr;
}

Matrix Matrix::operator*(const Matrix& m) const
{
    if(width != m.height)
        throw std::overflow_error("X та Y матриц не співпадаюсь");

    Matrix res(height, m.width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < m.width; j++)
        {
            res.matrix[i][j] = 0;
            for (int k = 0; k < width; k++)
            {
                res.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }

    return res;
}

Matrix Matrix::operator*(double num)
{
    Matrix mtr(height, width);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            mtr.matrix[i][j] = matrix[i][j] * num;
        }
    }

    return mtr;
}

Matrix Matrix::operator/(double num)
{
    if(num == 0)
        throw std::overflow_error("На нуль ділити не можна");

    Matrix mtr(height, width);

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            mtr.matrix[i][j] = matrix[i][j] / num;
        }
    }

    return mtr;
}

void Matrix::inverse()
{
//    if(width != height)
//        throw std::overflow_error("Матриця повинна бути квадратною");

//    double determinant = det();

//    if(determinant == 0)
//        throw std::overflow_error("Визначиник матрици дорівнює нулю");

//    transpose();
}

void Matrix::algebraicСomplement()
{

}

void Matrix::transpose()
{
     Matrix mtr(width, height);
     for(size_t i = 0; i < height; i++)
     {
        for(size_t j = 0; j < width; j++)
        {
            mtr.matrix[j][i] = matrix[i][j];
        }
     }

     build(mtr);

//     delete mtr;
}

double Matrix::det()
{
    if(width != height)
        throw std::overflow_error("Матриця повинна бути квадратною");

    double **arr = new double*[height];
    int n = 0;

    for(int i = 0; i < height; i++)
    {
        n++;
        arr[i] = new double[width];
        for(int j = 0; j < width; j++)
        {
            arr[i][j] = matrix[i][j];
        }
    }
    double num = findDet(arr, n);

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete [] arr;

    return num;
}

double Matrix::findDet(double **a, int n)
{
    if (n == 1)
            return a[0][0];
        else if (n == 2)
            return a[0][0] * a[1][1] - a[0][1] * a[1][0];
        else
        {
            int d = 0;
            for (int k = 0; k < n; k++)
            {
                double** m = new double*[n-1];
                for (int i = 0; i < n - 1; i++)
                {
                    m[i] = new double[n - 1];
                }
                for (int i = 1; i < n; i++)
                {
                    int t = 0;
                    for (int j = 0; j < n; j++)
                    {
                        if (j == k)
                            continue;
                        m[i-1][t] = a[i][j];
                        t++;
                    }
                }
                d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
                clearMemory(m, n - 1);
            }
            return d;
        }
}

void Matrix::clearMemory(double **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete [] arr;
}

double** Matrix::getMatrix()
{
    return matrix;
}
int Matrix::getWidth()
{
    return width;
}
int Matrix::getHeight()
{
    return height;
}
