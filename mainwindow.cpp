#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m1 = matrix(ui->Matrix_1, ui->outputLine, mSize(ui->spinBoxX_matrix_1->value(), ui->spinBoxY_matrix_1->value()));
    m2 = matrix(ui->Matrix_2, ui->outputLine, mSize(ui->spinBoxX_matrix_2->value(), ui->spinBoxY_matrix_2->value()));

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
    outputM = matrix(ui->Matrix_3, ui->outputLine);

    QString selected = ui->optionsBox->currentText();

    if(selected == "Сложить")
    {
        outputM.baseOp(m1, m2, sum);
    }
    else if(selected == ("Вычесть"))
    {
        outputM.baseOp(m1, m2, sub);
    }
    else if(selected == ("Умножить"))
    {
        outputM.multiply(m1, m2);
    }
}

// To matrix A
void MainWindow::on_matrixButon_convert_1_clicked()
{

}

void MainWindow::on_matrixButon_transpose_1_clicked()
{
    m1.transpose();
}

void MainWindow::on_matrixButon_determinant_1_clicked()
{
    m1.determinant();
}

void MainWindow::on_matrix_calc_1_clicked()
{
    QString selected = ui->matrix_operations_1->currentText();

    if(selected == "Умножить на")
    {
        m1.arithmetikOp(ui->matrix_line_1->text().toFloat(), multi);
    }
    else if(selected == ("Поделить на"))
    {
        m1.arithmetikOp(ui->matrix_line_1->text().toFloat(), divide);
    }
}

// To matrix B
void MainWindow::on_matrixButon_convert_2_clicked()
{

}

void MainWindow::on_matrixButon_transpose_2_clicked()
{
    m2.transpose();
}

void MainWindow::on_matrixButon_determinant_2_clicked()
{
    m2.determinant();
}

void MainWindow::on_matrix_calc_2_clicked()
{
    QString selected = ui->matrix_operations_2->currentText();

    if(selected == "Умножить на")
    {
        m2.arithmetikOp(ui->matrix_line_2->text().toFloat(), multi);
    }
    else if(selected == ("Поделить на"))
    {
        m2.arithmetikOp(ui->matrix_line_2->text().toFloat(), divide);
    }
}


// Moving
void MainWindow::on_result_to_A_clicked()
{
    m1.clone(outputM);
}

void MainWindow::on_result_to_B_clicked()
{
    m2.clone(outputM);
}

void MainWindow::on_toRight_clicked()
{
    m2.clone(m1);
    m1.build(m1.size);
}

void MainWindow::on_toLeft_clicked()
{
    m1.clone(m2);
    m2.build(m2.size);
}

