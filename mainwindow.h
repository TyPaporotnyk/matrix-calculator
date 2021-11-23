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

private:
    Ui::MainWindow *ui;

    matrix m1;
    matrix m2;

};
#endif // MAINWINDOW_H
