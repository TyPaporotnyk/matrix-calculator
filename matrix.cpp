#include "matrix.h"

#include <qheaderview.h>

matrix::matrix()
{
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
