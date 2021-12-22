#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdexcept>

#include "Linker.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m1.build(1,1);
    m2.build(1,1);

    link.display(m1, ui->Matrix_1);
    link.display(m2, ui->Matrix_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buildMatrixButton_1_clicked()
{
    int height = ui->spinBoxY_matrix_1->value();
    int width = ui->spinBoxX_matrix_1->value();

    m1.build(width, height);

    link.display(m1, ui->Matrix_1);
}

void MainWindow::on_buildMatrixButton_2_clicked()
{
    int height = ui->spinBoxY_matrix_2->value();
    int width = ui->spinBoxX_matrix_2->value();

    m2.build(width, height);

    link.display(m2, ui->Matrix_2);
}

void MainWindow::on_clearButton1_clicked()
{
    int height = ui->spinBoxX_matrix_1->value();
    int width = ui->spinBoxY_matrix_1->value();

    m1.build(width, height);

    link.display(m1, ui->Matrix_1);
}

void MainWindow::on_clearButton2_clicked()
{
    int height = ui->spinBoxX_matrix_2->value();
    int width = ui->spinBoxY_matrix_2->value();

    m2.build(width, height);

    link.display(m2, ui->Matrix_2);
}

void MainWindow::on_calculateButton_clicked()
{
    link.netToMatrix(ui->Matrix_1, m1);
    link.netToMatrix(ui->Matrix_2, m2);

    QString selected = ui->optionsBox->currentText();

    try{
        if(selected == "Скласти")
        {
            output = m1 + m2;
            link.display(output, ui->Matrix_3);
        }
        else if(selected == ("Відняти"))
        {
            output = m1 - m2;
            link.display(output, ui->Matrix_3);
        }
        else if(selected == ("Помножити"))
        {
            output = m1 * m2;
            link.display(output, ui->Matrix_3);
        }

        ui->outputLine->setText("");

        ui->result_to_A->setEnabled(true);
        ui->result_to_B->setEnabled(true);
    } catch (std::overflow_error ex) {
        ui->outputLine->setText(ex.what());
    }
}

// To matrix A

//void MainWindow::on_matrixButon_convert_1_clicked()
//{

//}

void MainWindow::on_matrixButon_transpose_1_clicked()
{
    link.netToMatrix(ui->Matrix_1, m1);
    m1.transpose();
    link.display(m1, ui->Matrix_1);
}

void MainWindow::on_matrixButon_determinant_1_clicked()
{
    link.netToMatrix(ui->Matrix_1, m1);

    try
    {
        double num = m1.det();
        ui->outputLine->setText(QString::number(num));
    } catch (std::overflow_error ex)
    {
        ui->outputLine->setText(ex.what());
    }
}

void MainWindow::on_matrix_calc_1_clicked()
{
    QString selected = ui->matrix_operations_1->currentText();

    link.netToMatrix(ui->Matrix_1, m1);

    double num = link.stringToNum(ui->matrix_line_1->text());

    try{
        if(selected == "Помножити на")
        {
            m1 = m1 * num;
            link.display(m1, ui->Matrix_1);
        }
        else if(selected == ("Поділити на"))
        {
            m1 = m1 / num;
            link.display(m1, ui->Matrix_1);
        }
    } catch(std::overflow_error ex){
        ui->outputLine->setText(ex.what());
    }
}

// To matrix B

//void MainWindow::on_matrixButon_convert_2_clicked()
//{

//}

void MainWindow::on_matrixButon_transpose_2_clicked()
{
    link.netToMatrix(ui->Matrix_2, m2);
    m2.transpose();
    link.display(m2, ui->Matrix_2);
}

void MainWindow::on_matrixButon_determinant_2_clicked()
{
    link.netToMatrix(ui->Matrix_2, m2);
    try
    {
        double num = m2.det();
        ui->outputLine->setText(QString::number(num));
    } catch (std::overflow_error ex)
    {
        ui->outputLine->setText(ex.what());
    }
}

void MainWindow::on_matrix_calc_2_clicked()
{
    QString selected = ui->matrix_operations_2->currentText();

    link.netToMatrix(ui->Matrix_2, m2);

    double num = link.stringToNum(ui->matrix_line_2->text());

    try{
        if(selected == "Помножити на")
        {
            m2 = m2 * num;
            link.display(m2, ui->Matrix_2);
        }
        else if(selected == ("Поділити на"))
        {
            m2 = m2 / num;
            link.display(m2, ui->Matrix_2);
        }
    } catch(std::overflow_error ex){
        ui->outputLine->setText(ex.what());
    }
}


// Moving
void MainWindow::on_result_to_A_clicked()
{
    link.netToMatrix(ui->Matrix_3, output);
    m1.build(output);
    link.display(m1, ui->Matrix_1);
}

void MainWindow::on_result_to_B_clicked()
{
    link.netToMatrix(ui->Matrix_3, output);
    m2.build(output);
    link.display(m2, ui->Matrix_2);
}

void MainWindow::on_toRight_clicked()
{
    link.netToMatrix(ui->Matrix_1, m1);
    m2.build(m1);
    link.display(m2, ui->Matrix_2);
}

void MainWindow::on_toLeft_clicked()
{
    link.netToMatrix(ui->Matrix_2, m2);
    m1.build(m2);
    link.display(m1, ui->Matrix_1);
}

