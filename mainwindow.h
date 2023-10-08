#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conjunto.h"
#include "QString"
#include "QMessageBox"
#include <chrono>

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
    void on_pushButton_gerar_clicked();

    void on_lineEdit_qtd_elementos_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
