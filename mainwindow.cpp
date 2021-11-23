#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

