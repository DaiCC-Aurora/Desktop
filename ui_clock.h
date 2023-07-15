/********************************************************************************
** Form generated from reading UI file 'clockLhTMBj.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLOCKLHTMBJ_H
#define CLOCKLHTMBJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clock
{
public:
    QTextBrowser *sen;
    QWidget *tomato;
    QWidget *weather;
    QLabel *time;

    void setupUi(QWidget *clock)
    {
        if (clock->objectName().isEmpty())
            clock->setObjectName("clock");
        clock->resize(720, 480);
        QFont font;
        font.setFamilies({QString::fromUtf8("HarmonyOS Sans SC")});
        font.setPointSize(16);
        clock->setFont(font);
        clock->setWindowOpacity(0.000000000000000);
        sen = new QTextBrowser(clock);
        sen->setObjectName("sen");
        sen->setGeometry(QRect(0, 280, 711, 192));
        tomato = new QWidget(clock);
        tomato->setObjectName("tomato");
        tomato->setGeometry(QRect(10, 130, 291, 141));
        weather = new QWidget(clock);
        weather->setObjectName("weather");
        weather->setGeometry(QRect(310, 140, 391, 131));
        time = new QLabel(clock);
        time->setObjectName("time");
        time->setGeometry(QRect(180, 0, 331, 91));

        retranslateUi(clock);

        QMetaObject::connectSlotsByName(clock);
    } // setupUi

    void retranslateUi(QWidget *clock)
    {
        clock->setWindowTitle(QCoreApplication::translate("clock", "time", nullptr));
        time->setText(QCoreApplication::translate("clock", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clock: public Ui_clock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLOCKLHTMBJ_H
