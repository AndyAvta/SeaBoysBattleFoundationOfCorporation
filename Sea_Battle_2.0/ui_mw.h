/********************************************************************************
** Form generated from reading ui file 'mw.ui'
**
** Created: Sun May 24 17:50:22 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MW_H
#define UI_MW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>
#include <QWidget>
#include <pole.h>
#include "record_frame.h"

QT_BEGIN_NAMESPACE

class Ui_MWClass
{
public:
    QWidget *centralWidget;
    pole *pole_1;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QCheckBox *cbp_1;
    QCheckBox *cbai_11;
    QLabel *label_3;
    QCheckBox *cbai_12;
    QCheckBox *cbai_13;
    QCheckBox *cbai_21;
    QCheckBox *cbai_23;
    QCheckBox *cbai_22;
    QLabel *label_4;
    QCheckBox *cbp_2;
    QTextEdit *p_1;
    QTextEdit *p_2;
    QPushButton *pushButton_4;
    record_frame *records;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MWClass)
    {
        if (MWClass->objectName().isEmpty())
            MWClass->setObjectName(QString::fromUtf8("MWClass"));
        MWClass->resize(730, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MWClass->sizePolicy().hasHeightForWidth());
        MWClass->setSizePolicy(sizePolicy);
        MWClass->setMinimumSize(QSize(730, 400));
        MWClass->setMaximumSize(QSize(730, 400));
        MWClass->setDocumentMode(false);
        MWClass->setDockOptions(QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MWClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pole_1 = new pole(centralWidget);
        pole_1->setObjectName(QString::fromUtf8("pole_1"));
        pole_1->setGeometry(QRect(120, 0, 471, 241));
        pole_1->setFrameShape(QFrame::StyledPanel);
        pole_1->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 290, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 260, 71, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 320, 71, 23));
        cbp_1 = new QCheckBox(centralWidget);
        cbp_1->setObjectName(QString::fromUtf8("cbp_1"));
        cbp_1->setGeometry(QRect(0, 20, 91, 18));
        cbai_11 = new QCheckBox(centralWidget);
        cbai_11->setObjectName(QString::fromUtf8("cbai_11"));
        cbai_11->setGeometry(QRect(0, 50, 81, 18));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 40, 46, 14));
        cbai_12 = new QCheckBox(centralWidget);
        cbai_12->setObjectName(QString::fromUtf8("cbai_12"));
        cbai_12->setGeometry(QRect(0, 70, 91, 18));
        cbai_13 = new QCheckBox(centralWidget);
        cbai_13->setObjectName(QString::fromUtf8("cbai_13"));
        cbai_13->setGeometry(QRect(0, 90, 91, 18));
        cbai_21 = new QCheckBox(centralWidget);
        cbai_21->setObjectName(QString::fromUtf8("cbai_21"));
        cbai_21->setGeometry(QRect(610, 30, 81, 61));
        cbai_23 = new QCheckBox(centralWidget);
        cbai_23->setObjectName(QString::fromUtf8("cbai_23"));
        cbai_23->setGeometry(QRect(610, 90, 91, 18));
        cbai_22 = new QCheckBox(centralWidget);
        cbai_22->setObjectName(QString::fromUtf8("cbai_22"));
        cbai_22->setGeometry(QRect(610, 68, 91, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(630, 40, 46, 14));
        cbp_2 = new QCheckBox(centralWidget);
        cbp_2->setObjectName(QString::fromUtf8("cbp_2"));
        cbp_2->setGeometry(QRect(610, 20, 81, 18));
        p_1 = new QTextEdit(centralWidget);
        p_1->setObjectName(QString::fromUtf8("p_1"));
        p_1->setGeometry(QRect(0, 0, 91, 16));
        p_1->setMaximumSize(QSize(120, 21));
        QFont font;
        font.setPointSize(7);
        p_1->setFont(font);
        p_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p_2 = new QTextEdit(centralWidget);
        p_2->setObjectName(QString::fromUtf8("p_2"));
        p_2->setGeometry(QRect(600, 0, 91, 16));
        p_2->setMaximumSize(QSize(120, 21));
        p_2->setFont(font);
        p_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        p_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 300, 75, 23));
        records = new record_frame(centralWidget);
        records->setObjectName(QString::fromUtf8("records"));
        records->setGeometry(QRect(110, 0, 411, 241));
        records->setFrameShape(QFrame::StyledPanel);
        records->setFrameShadow(QFrame::Raised);
        MWClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MWClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 730, 25));
        MWClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MWClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MWClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MWClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MWClass->setStatusBar(statusBar);

        retranslateUi(MWClass);

        QMetaObject::connectSlotsByName(MWClass);
    } // setupUi

    void retranslateUi(QMainWindow *MWClass)
    {
        MWClass->setWindowTitle(QApplication::translate("MWClass", "MW", 0));
        pushButton->setText(QApplication::translate("MWClass", "\320\222\321\213\321\205\320\276\320\264", 0));
        pushButton_2->setText(QApplication::translate("MWClass", "\320\240\320\265\321\201\321\202\320\260\321\200\321\202", 0));
        pushButton_3->setText(QApplication::translate("MWClass", "\320\221\320\236\320\231", 0));
        cbp_1->setText(QApplication::translate("MWClass", "\320\247\320\265\320\273\320\276\320\262\320\265\320\272", 0));
        cbai_11->setText(QApplication::translate("MWClass", "\320\233\320\265\320\263\320\272\320\270\320\271", 0));
        label_3->setText(QApplication::translate("MWClass", "\320\237\320\232", 0));
        cbai_12->setText(QApplication::translate("MWClass", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", 0));
        cbai_13->setText(QApplication::translate("MWClass", "\320\241\320\273\320\276\320\266\320\275\321\213\320\271", 0));
        cbai_21->setText(QApplication::translate("MWClass", "\320\233\320\265\320\263\320\272\320\270\320\271", 0));
        cbai_23->setText(QApplication::translate("MWClass", "\320\241\320\273\320\276\320\266\320\275\321\213\320\271", 0));
        cbai_22->setText(QApplication::translate("MWClass", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", 0));
        label_4->setText(QApplication::translate("MWClass", "\320\237\320\232", 0));
        cbp_2->setText(QApplication::translate("MWClass", "\320\247\320\265\320\273\320\276\320\262\320\265\320\272", 0));
        p_1->setHtml(QApplication::translate("MWClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">easy</span></p></body></html>", 0));
        p_2->setHtml(QApplication::translate("MWClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">player2</span></p></body></html>", 0));
        pushButton_4->setText(QApplication::translate("MWClass", "\320\240\320\265\320\272\320\276\321\200\320\264\321\213", 0));
        Q_UNUSED(MWClass);
    } // retranslateUi

};

namespace Ui {
    class MWClass: public Ui_MWClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MW_H
