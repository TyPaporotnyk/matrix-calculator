#include "Linker.h"
#include <string>
#include <iomanip>

void Linker::display(Matrix& m, QTableWidget *net)
{
    net->setColumnCount(m.getWidth());
    net->setRowCount(m.getHeight());

    int width = (net->width() - 20) / m.getWidth();
    int height = (net->height() - 20) / m.getHeight();

    for(int i = 0; i < m.getHeight(); i++)
    {
        for(int j = 0; j < m.getWidth(); j++)
        {
           net->setColumnWidth(j, width);

           net->setItem(i, j, new QTableWidgetItem(QString::number(m.getMatrix()[i][j])));
           net->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }

        net->setRowHeight(i, height);
    }
}

void Linker::netToMatrix(QTableWidget *net, Matrix& m)
{
    for(int i = 0; i < m.getHeight(); i++)
    {
        for(int j = 0; j < m.getWidth(); j++)
        {
            m.getMatrix()[i][j] = stringToNum(net->item(i, j)->text());
        }
    }
}

double Linker::stringToNum(QString str)
{
    return std::atof(str.toStdString().c_str());
}
