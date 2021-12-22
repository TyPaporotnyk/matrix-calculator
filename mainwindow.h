#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "matrix.h"
#include "Linker.h"

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
    void on_matrixButon_transpose_1_clicked();
    void on_matrixButon_determinant_1_clicked();
    void on_matrix_calc_1_clicked();

    // To matrix B
    void on_matrixButon_transpose_2_clicked();
    void on_matrixButon_determinant_2_clicked();
    void on_matrix_calc_2_clicked();

    // Moving
    void on_result_to_A_clicked();
    void on_result_to_B_clicked();
    void on_toRight_clicked();
    void on_toLeft_clicked();

private:
    Ui::MainWindow *ui;

    Linker link;

    Matrix m1;
    Matrix m2;
    Matrix output;
};
#endif // MAINWINDOW_H
