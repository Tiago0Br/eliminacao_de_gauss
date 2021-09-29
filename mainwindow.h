#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_matriz_a11_valueChanged(const QString &arg1);

    void on_matriz_a12_valueChanged(const QString &arg1);

    void on_matriz_a13_valueChanged(const QString &arg1);

    void on_matriz_a14_valueChanged(const QString &arg1);

    void on_matriz_a21_valueChanged(const QString &arg1);

    void on_matriz_a22_valueChanged(const QString &arg1);

    void on_matriz_a23_valueChanged(const QString &arg1);

    void on_matriz_a24_valueChanged(const QString &arg1);

    void on_matriz_a31_valueChanged(const QString &arg1);

    void on_matriz_a32_valueChanged(const QString &arg1);

    void on_matriz_a33_valueChanged(const QString &arg1);

    void on_matriz_a34_valueChanged(const QString &arg1);

    void on_btn_calc_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
