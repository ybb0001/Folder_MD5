/********************************************************************************
** Form generated from reading UI file 'Folder_MD5.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOLDER_MD5_H
#define UI_FOLDER_MD5_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Folder_MD5Class
{
public:
    QWidget *centralWidget;
    QTextBrowser *data_Base;
    QTextBrowser *current_Data;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_save;
    QPushButton *pushButton_check;
    QTextBrowser *Result;
    QLabel *label_3;
    QPushButton *pushButton_login;
    QLineEdit *pw;
    QLabel *label_4;

    void setupUi(QMainWindow *Folder_MD5Class)
    {
        if (Folder_MD5Class->objectName().isEmpty())
            Folder_MD5Class->setObjectName(QStringLiteral("Folder_MD5Class"));
        Folder_MD5Class->resize(640, 480);
        Folder_MD5Class->setAutoFillBackground(false);
        Folder_MD5Class->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(Folder_MD5Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        data_Base = new QTextBrowser(centralWidget);
        data_Base->setObjectName(QStringLiteral("data_Base"));
        data_Base->setGeometry(QRect(5, 15, 630, 250));
        current_Data = new QTextBrowser(centralWidget);
        current_Data->setObjectName(QStringLiteral("current_Data"));
        current_Data->setGeometry(QRect(5, 285, 630, 140));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 231, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 270, 231, 16));
        pushButton_save = new QPushButton(centralWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setEnabled(false);
        pushButton_save->setGeometry(QRect(5, 430, 80, 30));
        pushButton_check = new QPushButton(centralWidget);
        pushButton_check->setObjectName(QStringLiteral("pushButton_check"));
        pushButton_check->setGeometry(QRect(550, 430, 81, 30));
        Result = new QTextBrowser(centralWidget);
        Result->setObjectName(QStringLiteral("Result"));
        Result->setGeometry(QRect(490, 430, 50, 30));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 460, 231, 20));
        pushButton_login = new QPushButton(centralWidget);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setGeometry(QRect(230, 430, 50, 30));
        pw = new QLineEdit(centralWidget);
        pw->setObjectName(QStringLiteral("pw"));
        pw->setGeometry(QRect(120, 430, 110, 30));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 440, 21, 16));
        Folder_MD5Class->setCentralWidget(centralWidget);

        retranslateUi(Folder_MD5Class);

        QMetaObject::connectSlotsByName(Folder_MD5Class);
    } // setupUi

    void retranslateUi(QMainWindow *Folder_MD5Class)
    {
        Folder_MD5Class->setWindowTitle(QApplication::translate("Folder_MD5Class", "Folder_MD5_V1_241114", Q_NULLPTR));
        label->setText(QApplication::translate("Folder_MD5Class", "Original Folder File list & MD5", Q_NULLPTR));
        label_2->setText(QApplication::translate("Folder_MD5Class", "Current Folder File list & MD5", Q_NULLPTR));
        pushButton_save->setText(QApplication::translate("Folder_MD5Class", "Origin Save", Q_NULLPTR));
        pushButton_check->setText(QApplication::translate("Folder_MD5Class", "Current Chk", Q_NULLPTR));
        Result->setHtml(QApplication::translate("Folder_MD5Class", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Result</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Folder_MD5Class", "supported by songye.guo@samsung.com", Q_NULLPTR));
        pushButton_login->setText(QApplication::translate("Folder_MD5Class", "login", Q_NULLPTR));
        label_4->setText(QApplication::translate("Folder_MD5Class", "PW:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Folder_MD5Class: public Ui_Folder_MD5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOLDER_MD5_H
