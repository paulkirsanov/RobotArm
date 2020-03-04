/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Close;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QSplitter *splitter;
    QLineEdit *lineEdit;
    QPushButton *rightButton;
    QSplitter *splitter_2;
    QLineEdit *lineEdit_2;
    QPushButton *leftButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(378, 222);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(378, 222));
        MainWindow->setMaximumSize(QSize(378, 222));
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,151,57);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 10, 69, 20));
        pushButton_Open = new QPushButton(centralWidget);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));
        pushButton_Open->setGeometry(QRect(185, 9, 75, 23));
        pushButton_Open->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,151,57);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_Close = new QPushButton(centralWidget);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(266, 9, 75, 23));
        pushButton_Close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,151,57);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(51, 9, 53, 23));
        label_2->setAlignment(Qt::AlignCenter);
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(130, 120, 131, 22));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(200, 50, 133, 51));
        splitter->setOrientation(Qt::Vertical);
        lineEdit = new QLineEdit(splitter);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        splitter->addWidget(lineEdit);
        rightButton = new QPushButton(splitter);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));
        rightButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,151,57);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        splitter->addWidget(rightButton);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(40, 50, 133, 51));
        splitter_2->setOrientation(Qt::Vertical);
        lineEdit_2 = new QLineEdit(splitter_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        splitter_2->addWidget(lineEdit_2);
        leftButton = new QPushButton(splitter_2);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));
        leftButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,151,57);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        splitter_2->addWidget(leftButton);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 378, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Control", nullptr));
        pushButton_Open->setText(QApplication::translate("MainWindow", "Open", nullptr));
        pushButton_Close->setText(QApplication::translate("MainWindow", "Close", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Serial port:", nullptr));
        rightButton->setText(QApplication::translate("MainWindow", "Right", nullptr));
        leftButton->setText(QApplication::translate("MainWindow", "Left", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
