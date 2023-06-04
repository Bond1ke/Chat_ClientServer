/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(262, 391);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"    background: red;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #212529;\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #6c757d;\n"
"    border-radius: 8.4px;\n"
"    padding: 1 15 0px 15px;\n"
"    background: #B22222;\n"
"    color: #f8f9fa;\n"
"    font: 600 10pt \"SF Pro Text\";\n"
"}"));

        gridLayout->addWidget(pushButton_3, 6, 0, 1, 2);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setEnabled(true);
        QFont font;
        font.setFamilies({QString::fromUtf8("SF Pro Text")});
        font.setPointSize(8);
        font.setBold(true);
        font.setItalic(false);
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser{\n"
"border: 1.5px solid #495057;\n"
"background-color : #343a40;\n"
"color: #f8f9fa;\n"
"font: 600 8pt \"SF Pro Text\";\n"
"border-radius: 10px;\n"
"}"));

        gridLayout->addWidget(textBrowser, 2, 0, 1, 2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #6c757d;\n"
"    border-radius: 8.4px;\n"
"    padding: 1 15 0px 15px;\n"
"    background: #495057;\n"
"    color: #f8f9fa;\n"
"    font: 600 10pt \"SF Pro Text\";\n"
"}"));

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    border: 1.5px solid #495057;\n"
"    border-radius: 8.4px;\n"
"    padding: 0 0 1px 8px;\n"
"    background: #343a40;\n"
"    color: #f8f9fa;\n"
"    font: 600 8pt \"SF Pro Text\";\n"
"    selection-background-color: darkgray;\n"
"}"));

        gridLayout->addWidget(lineEdit, 4, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #6c757d;\n"
"    border-radius: 8.4px;\n"
"    background: #495057;\n"
"    color: #f8f9fa;\n"
"    font: 600 10pt \"SF Pro Text\";\n"
"}"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 2);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #6c757d;\n"
"    border-radius: 8.4px;\n"
"    padding: 1 15 0px 15px;\n"
"    background: #4682B4;\n"
"    color: #f8f9fa;\n"
"    font: 600 10pt \"SF Pro Text\";\n"
"}"));

        gridLayout->addWidget(pushButton_4, 5, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'SF Pro Text'; font-size:8pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MV Boli'; font-size:9pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
