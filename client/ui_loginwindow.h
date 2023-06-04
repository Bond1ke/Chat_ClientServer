/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->setEnabled(true);
        LoginWindow->resize(178, 77);
        LoginWindow->setMinimumSize(QSize(0, 0));
        LoginWindow->setMaximumSize(QSize(178, 100));
        LoginWindow->setLayoutDirection(Qt::LeftToRight);
        LoginWindow->setStyleSheet(QString::fromUtf8("QDialog{\n"
"background-color: #212529;\n"
"}"));
        LoginWindow->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(LoginWindow);
        gridLayout->setObjectName("gridLayout");
        buttonBox = new QDialogButtonBox(LoginWindow);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #6c757d;\n"
"    border-radius: 8.4px;\n"
"    padding: 1 15 0px 15px;\n"
"    background: #495057;\n"
"    color: #f8f9fa;\n"
"    font: 600 10pt \"SF Pro Text\";\n"
"}"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1, Qt::AlignHCenter);

        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #f8f9fa;\n"
"    font: 600 15pt \"SF Pro Text\";\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(LoginWindow);
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

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);


        retranslateUi(LoginWindow);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, LoginWindow, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, LoginWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Enter Username below", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
