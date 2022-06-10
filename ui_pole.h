/********************************************************************************
** Form generated from reading ui file 'pole.ui'
**
** Created: Thu 16. Apr 21:21:00 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_POLE_H
#define UI_POLE_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QFrame>
#include <QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_pole
{
public:

    void setupUi(QFrame *pole)
    {
        if (pole->objectName().isEmpty())
            pole->setObjectName(QString::fromUtf8("pole"));
        pole->resize(400, 300);
        pole->setFrameShape(QFrame::StyledPanel);
        pole->setFrameShadow(QFrame::Raised);

        retranslateUi(pole);

        QMetaObject::connectSlotsByName(pole);
    } // setupUi

    void retranslateUi(QFrame *pole)
    {
        pole->setWindowTitle(QApplication::translate("pole", "Frame", 0));
        Q_UNUSED(pole);
    } // retranslateUi

};

namespace Ui {
    class pole: public Ui_pole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLE_H
