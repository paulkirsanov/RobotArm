/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QSlider *horizontalSlider;
    QFrame *line;
    QFrame *line_2;
    QLabel *label;
    QSplitter *splitter;
    QLineEdit *lineEdit;
    QPushButton *rightButton;
    QSplitter *splitter_2;
    QLineEdit *lineEdit_2;
    QPushButton *leftButton;
    QPushButton *pushButton_AutoMode;
    QFrame *line_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(372, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(372, 200));
        MainWindow->setMaximumSize(QSize(372, 300));
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral("icons.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(255,151,57);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 10, 69, 20));
        pushButton_Open = new QPushButton(centralWidget);
        pushButton_Open->setObjectName(QStringLiteral("pushButton_Open"));
        pushButton_Open->setGeometry(QRect(185, 9, 75, 23));
        pushButton_Open->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(182,189,184);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #9C978B, stop: 1 #7A7466);\n"
"}"));
        pushButton_Close = new QPushButton(centralWidget);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(266, 9, 75, 23));
        pushButton_Close->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(182,189,184);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #9C978B, stop: 1 #7A7466);\n"
"}"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(51, 9, 53, 23));
        label_2->setAlignment(Qt::AlignCenter);
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(40, 140, 131, 22));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(190, 140, 141, 22));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setPageStep(8);
        horizontalSlider->setValue(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickInterval(0);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 120, 351, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 40, 351, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 130, 47, 41));
        label->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(200, 60, 133, 51));
        splitter->setOrientation(Qt::Vertical);
        lineEdit = new QLineEdit(splitter);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setAlignment(Qt::AlignCenter);
        splitter->addWidget(lineEdit);
        rightButton = new QPushButton(splitter);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(182,189,184);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #9C978B, stop: 1 #7A7466);\n"
"}"));
        splitter->addWidget(rightButton);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(40, 60, 133, 51));
        splitter_2->setOrientation(Qt::Vertical);
        lineEdit_2 = new QLineEdit(splitter_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        splitter_2->addWidget(lineEdit_2);
        leftButton = new QPushButton(splitter_2);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(182,189,184);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #9C978B, stop: 1 #7A7466);\n"
"}"));
        splitter_2->addWidget(leftButton);
        pushButton_AutoMode = new QPushButton(centralWidget);
        pushButton_AutoMode->setObjectName(QStringLiteral("pushButton_AutoMode"));
        pushButton_AutoMode->setGeometry(QRect(140, 210, 75, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(182, 189, 184, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        pushButton_AutoMode->setPalette(palette);
        pushButton_AutoMode->setStyleSheet(QLatin1String("QPushButton{\n"
"	background-color: rgb(182,189,184);\n"
"	color:while;\n"
"	border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"									stop: 0 #9C978B, stop: 1 #7A7466);\n"
"}"));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 180, 351, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 372, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        label->setText(QApplication::translate("MainWindow", "1", nullptr));
        rightButton->setText(QApplication::translate("MainWindow", "Close", nullptr));
        leftButton->setText(QApplication::translate("MainWindow", "Open", nullptr));
        pushButton_AutoMode->setText(QApplication::translate("MainWindow", "Auto Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
