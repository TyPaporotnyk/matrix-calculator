#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int index = 0; index < ui->optionsBox->count(); index++)
        itemsInComboBox << ui->optionsBox->itemText(index);

    m1 = matrix(ui->Matrix_1, mSize(ui->spinBoxX_matrix_1->value(), ui->spinBoxY_matrix_1->value()));
    m2 = matrix(ui->Matrix_2, mSize(ui->spinBoxX_matrix_2->value(), ui->spinBoxY_matrix_2->value()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buildMatrixButton_1_clicked()
{
    m1.build(mSize(ui->spinBoxX_matrix_1->value(), ui->spinBoxY_matrix_1->value()));
}

void MainWindow::on_buildMatrixButton_2_clicked()
{
    m2.build(mSize(ui->spinBoxX_matrix_2->value(), ui->spinBoxY_matrix_2->value()));
}

void MainWindow::on_clearButton1_clicked()
{
    m1.clear();
}

void MainWindow::on_clearButton2_clicked()
{
    m2.clear();

}

void MainWindow::on_calculateButton_clicked()
{
    outputM = matrix(ui->Matrix_3);

    QString selected = ui->optionsBox->currentText();

    if(selected == "Сложить")
    {
        outputM.baseOp(ui->outputLine, m1, m2, sum);
    }
    else if(selected == ("Вычесть"))
    {
        outputM.baseOp(ui->outputLine, m1, m2, sub);
    }
    else if(selected == ("Умножить на"))
    {
        outputM.arithmetikOp(ui->outputLine, m1, ui->numLine->text().toFloat(), multi);
    }
    else if(selected == ("Поделить на"))
    {
        outputM.arithmetikOp(ui->outputLine, m1, ui->numLine->text().toFloat(), divide);
    }
    else if(selected == ("Умножить"))
    {
        outputM.multiply(ui->outputLine, m1, m2);
    }
    else if(selected == ("Определитель"))
    {
        m1.determinant(ui->outputLine);
    }
}

