/********************************************************************************
** Form generated from reading UI file 'toolTFYCkd.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TOOLTFYCKD_H
#define TOOLTFYCKD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tool
{
public:

    void setupUi(QWidget *Tool)
    {
        if (Tool->objectName().isEmpty())
            Tool->setObjectName("Tool");
        Tool->resize(550, 400);

        retranslateUi(Tool);

        QMetaObject::connectSlotsByName(Tool);
    } // setupUi

    void retranslateUi(QWidget *Tool)
    {
        Tool->setWindowTitle(QCoreApplication::translate("Tool", "tool", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tool: public Ui_Tool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TOOLTFYCKD_H
