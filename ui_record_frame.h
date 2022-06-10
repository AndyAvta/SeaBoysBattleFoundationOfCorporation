/********************************************************************************
** Form generated from reading ui file 'record_frame.ui'
**
** Created: Wed 6. May 22:28:47 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RECORD_FRAME_H
#define UI_RECORD_FRAME_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QFrame>
#include <QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_record_frame
{
public:

    void setupUi(QFrame *record_frame)
    {
        if (record_frame->objectName().isEmpty())
            record_frame->setObjectName(QString::fromUtf8("record_frame"));
        record_frame->setFrameShadow(QFrame::Raised);
        record_frame->resize(400, 300);
        record_frame->setFrameShape(QFrame::StyledPanel);

        retranslateUi(record_frame);

        QMetaObject::connectSlotsByName(record_frame);
    } // setupUi

    void retranslateUi(QFrame *record_frame)
    {
        record_frame->setWindowTitle(QApplication::translate("record_frame", "Frame", 0));
        Q_UNUSED(record_frame);
    } // retranslateUi

};

namespace Ui {
    class record_frame: public Ui_record_frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_FRAME_H
