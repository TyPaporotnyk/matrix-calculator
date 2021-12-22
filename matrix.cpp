#include "matrix.h"
#include <stdexcept>

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
            mtr.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
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
