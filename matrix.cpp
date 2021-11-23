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

    int width = (net->width() - net->horizontalHeader()->height()) / size.sizeX;
    int height = (net->height() - net->verticalHeader()->width()) / size.sizeY;

    for(int y = 0; y < size.sizeY; y++)
    {
        for(int x = 0; x < size.sizeX; x++)
        {
           net->setColumnWidth(x, width);
           //net->item(y,x)->setTextAlignment()
           //net->item(x,y)->setText(QString("Hello World"));
        }

        net->setRowHeight(y, height);
    }
}
