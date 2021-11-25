#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matrix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_buildMatrixButton_1_clicked();
    void on_buildMatrixButton_2_clicked();

    void on_clearButton1_clicked();
    void on_clearButton2_clicked();

    void on_calculateButton_clicked();

    // To matrix A
    void on_matrixButon_convert_1_clicked();
    void on_matrixButon_transpose_1_clicked();
    void on_matrixButon_determinant_1_clicked();
    void on_matrix_calc_1_clicked();

    // To matrix B
    void on_matrixButon_convert_2_clicked();
    void on_matrixButon_transpose_2_clicked();
    void on_matrixButon_determinant_2_clicked();
    void on_matrix_calc_2_clicked();

    void on_result_to_A_clicked();

    void on_result_to_B_clicked();

private:
    Ui::MainWindow *ui;

    matrix m1;
    matrix m2;
    matrix outputM;
};
#endif // MAINWINDOW_H
