#include "matrix.h"

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

void matrix::sum(QLineEdit* e, matrix m1, matrix m2)
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
            net->item(y, x)->setText(QString::number(m1.net->item(y, x)->text().toInt() +
                                                     m2.net->item(y, x)->text().toInt()));
        }
    }
}

void matrix::sub(QLineEdit* e, matrix m1, matrix m2)
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
            net->item(y, x)->setText(QString::number(m1.net->item(y, x)->text().toInt() -
                                                     m2.net->item(y, x)->text().toInt()));
        }
    }
}

void matrix::multyply(QLineEdit* e , matrix m1, matrix m2)
{
    e->setText("");
}

void matrix::multyplyOn(QLineEdit* e , matrix m1, float a)
{
    e->setText("");
    build(m1.size);

    for(int y = 0; y < size.sizeY; y++)
    {
        for(int x = 0; x < size.sizeX; x++)
        {
            net->item(y, x)->setText(QString::number(m1.net->item(y, x)->text().toInt() * a));
        }
    }
}

void matrix::devideOn(QLineEdit* e , matrix m1, float a)
{
    e->setText("");
    if(a == 0)
    {
        e->setText("На ноль делить нельзя");
        return;
    }

    build(m1.size);

    for(int y = 0; y < size.sizeY; y++)
    {
        for(int x = 0; x < size.sizeX; x++)
        {
            net->item(y, x)->setText(QString::number(m1.net->item(y, x)->text().toInt() / a));
        }
    }
}