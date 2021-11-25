#include "matrix.h"

#include <stdexcept>
#include <qheaderview.h>
#include <QString>

matrix::matrix()
{

}

matrix::matrix(QTableWidget* _net)
{
    net = _net;
}

matrix::matrix(QTableWidget* _net, mSize _size)
{
    net = _net;
    build(_size);
}

void matrix::build(mSize _size)
{
    size = _size;

    net->setColumnCount(size.sizeX);
    net->setRowCount(size.sizeY);

    net->horizontalHeader();

    int width = (net->width() - 20) / size.sizeX;
    int height = (net->height() - 20) / size.sizeY;

    for(int y = 0; y < size.sizeY; y++)
    {
        for(int x = 0; x < size.sizeX; x++)
        {
           net->setColumnWidth(x, width);

           net->setItem(y, x, new QTableWidgetItem("0"));
           net->item(y,x)->setTextAlignment(Qt::AlignCenter);
        }

        net->setRowHeight(y, height);
    }
}

void matrix::clear()
{
    for(int y = 0; y < size.sizeY; y++)
    {
        for(int x = 0; x < size.sizeX; x++)
        {
           net->item(y, x)->setText("0");
        }
    }
}

void matrix::baseOp(QLineEdit* e, matrix m1, matrix m2, float(*f)(float a, float b))
{
    e->setText("");
    if(m1.size.sizeX != m2.size.sizeX || m1.size.sizeY != m2.size.sizeY)
    {
        e->setText("Размеры матриц не совпадают");
        return;
    }

    build(m1.size);

    for(int y = 0; y < size.sizeY; y++)
    {
        for(int x = 0; x < size.sizeX; x++)
        {
            net->item(y, x)->setText(QString::number(f(m1.net->item(y, x)->text().toInt(),
                                                       m2.net->item(y, x)->text().toInt())));
        }
    }
}

void matrix::multiply(QLineEdit* e , matrix m1, matrix m2)
{
    e->setText("");
    if(m1.size.sizeY != m2.size.sizeX)
    {
        e->setText("Размеры матриц не совпадают");
        return;
    }

    build(mSize(m1.size.sizeY, m2.size.sizeX));

    for (int i = 0; i < m1.size.sizeY; i++)
    {
        for (int j = 0; j < m2.size.sizeX; j++)
        {
            float sum = 0;
            for (int k = 0; k < m1.size.sizeX; k++)
            {
                sum += m1.net->item(i, k)->text().toFloat() * m2.net->item(k, j)->text().toFloat();
            }
            net->item(i,j)->setText(QString::number(sum));
        }
    }

}

void matrix::arithmetikOp(QLineEdit* e , float a, float(*f)(float a, float b))
{
    e->setText("");

    for(int y = 0; y < size.sizeY; y++)
    {
        for(int x = 0; x < size.sizeX; x++)
        {
            try
            {
                net->item(y, x)->setText(QString::number(f(net->item(y, x)->text().toInt(), a)));
            } catch(std::overflow_error ex)
            {
                e->setText(ex.what());
            }
        }
    }
}

void matrix::determinant(QLineEdit* e)
{
    if(size.sizeX != size.sizeY)
    {
        e->setText("Не квадратная матрица");
        return;
    }

    float **arr = new float*[size.sizeY];
    int n = 0;

    for(int i = 0; i < size.sizeX; i++)
    {
        n++;
        arr[i] = new float[size.sizeY];
        for(int j = 0; j < size.sizeX; j++)
        {
            arr[i][j] = net->item(i,j)->text().toFloat();
        }
    }

    float det = findDet(arr, n);

    char str[100];
    sprintf(str, "Определитель равен: %5.2f", det);

    e->setText(str);
}

void matrix::clearMemory(float** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete [] a;
}

float matrix::findDet(float** a, int n)
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
            float** m = new float*[n-1];
            for (int i = 0; i < n - 1; i++)
            {
                m[i] = new float[n - 1];
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

float sum(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float multi(float a, float b) { return a * b; }
float divide(float a, float b)
{
    if (b == 0)
            throw std::overflow_error("На ноль делить нельзя");
    return a / b;
}
