#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QMessageBox>

QSerialPort serial;

int value_slider = 1;
bool key = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->comboBox->addItem(info.portName());
    }

    ui->comboBox_2->addItem("FULL STEP");
    ui->comboBox_2->addItem("HALF STEP");
    ui->comboBox_2->addItem("QUARTER STEP");
    ui->comboBox_2->addItem("EIGHTH STEP");
    ui->comboBox_2->addItem("SIXTEENTH STEP");

    ui->horizontalSlider->setMinimum(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Open_clicked()
{
    if(serial.portName() != ui->comboBox->currentText())
    {
        serial.close();
        serial.setPortName(ui->comboBox->currentText());
    }

    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QSerialPort::WriteOnly);
    if(serial.isOpen())
    {
        ui->statusBar->showMessage("Open");
    }
}

void MainWindow::on_pushButton_Close_clicked()
{
    serial.close();
    if(!serial.isOpen())
    {
        ui->statusBar->showMessage("Close");
    }
}

void MainWindow::on_rightButton_clicked()
{
    //key = false;
    QString str1 = ui->lineEdit->text();
    serial.putChar(0xF8); //START BIT
    serial.putChar(0x52); //RIGHT

    if(ui->comboBox_2->currentText() == "FULL STEP")
        serial.putChar(0x46);
    else if(ui->comboBox_2->currentText() == "HALF STEP")
        serial.putChar(0x48);
    else if(ui->comboBox_2->currentText() == "QUARTER STEP")
        serial.putChar(0x51);
    else if(ui->comboBox_2->currentText() == "EIGHTH STEP")
        serial.putChar(0x45);
    else if(ui->comboBox_2->currentText() == "SIXTEENTH STEP")
        serial.putChar(0x53);

    int16_t value = str1.toLong();
    int first = value & 0xFF;
    int second = value >> 8;
    serial.putChar(second); //SECOND BIT
    serial.putChar(first); //FIRST BIT

    serial.putChar(0x00);
    serial.putChar(value_slider);

    serial.putChar(0xE0); //STOP BIT
}

void MainWindow::on_leftButton_clicked()
{
    //key = false;
    QString str2 = ui->lineEdit_2->text();
    serial.putChar(0xF8); //START BIT
    serial.putChar(0x4C); //LEFT

    if(ui->comboBox_2->currentText() == "FULL STEP")
        serial.putChar(0x46);
    else if(ui->comboBox_2->currentText() == "HALF STEP")
        serial.putChar(0x48);
    else if(ui->comboBox_2->currentText() == "QUARTER STEP")
        serial.putChar(0x51);
    else if(ui->comboBox_2->currentText() == "EIGHTH STEP")
        serial.putChar(0x45);
    else if(ui->comboBox_2->currentText() == "SIXTEENTH STEP")
        serial.putChar(0x53);

    int16_t value = str2.toLong();
    int first = value & 0xFF;
    int second = value >> 8;
    serial.putChar(second); //SECOND BIT
    serial.putChar(first); //FIRST BIT

    serial.putChar(0x00);
    serial.putChar(value_slider);

    serial.putChar(0xE0); //STOP BIT
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setNum(value);
    value_slider = value;
}

void MainWindow::on_pushButton_AutoMode_clicked()
{
    /*key = true;
    while(key)
    {*/
        QString str1 = ui->lineEdit->text();
        serial.putChar(0xF8); //START BIT
        serial.putChar(0x52); //RIGHT

        if(ui->comboBox_2->currentText() == "FULL STEP")
            serial.putChar(0x46);
        else if(ui->comboBox_2->currentText() == "HALF STEP")
            serial.putChar(0x48);
        else if(ui->comboBox_2->currentText() == "QUARTER STEP")
            serial.putChar(0x51);
        else if(ui->comboBox_2->currentText() == "EIGHTH STEP")
            serial.putChar(0x45);
        else if(ui->comboBox_2->currentText() == "SIXTEENTH STEP")
            serial.putChar(0x53);

        int16_t value1 = str1.toLong();
        int first1 = value1 & 0xFF;
        int second1 = value1 >> 8;
        serial.putChar(second1); //SECOND BIT
        serial.putChar(first1); //FIRST BIT

        serial.putChar(0x00);
        serial.putChar(value_slider);

        serial.putChar(0xE0); //STOP BIT

        /* ---------------------------------*/


        QString str2 = ui->lineEdit_2->text();
        serial.putChar(0xF8); //START BIT
        serial.putChar(0x4C); //LEFT

        if(ui->comboBox_2->currentText() == "FULL STEP")
            serial.putChar(0x46);
        else if(ui->comboBox_2->currentText() == "HALF STEP")
            serial.putChar(0x48);
        else if(ui->comboBox_2->currentText() == "QUARTER STEP")
            serial.putChar(0x51);
        else if(ui->comboBox_2->currentText() == "EIGHTH STEP")
            serial.putChar(0x45);
        else if(ui->comboBox_2->currentText() == "SIXTEENTH STEP")
            serial.putChar(0x53);

        int16_t value2 = str2.toLong();
        int first2 = value2 & 0xFF;
        int second2 = value2 >> 8;
        serial.putChar(second2); //SECOND BIT
        serial.putChar(first2); //FIRST BIT

        serial.putChar(0x00);
        serial.putChar(value_slider);

        serial.putChar(0xE0); //STOP BIT
    //}

}
