#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Open_clicked();

    void on_pushButton_Close_clicked();

    void on_rightButton_clicked();

    void on_leftButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_AutoMode_clicked();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
