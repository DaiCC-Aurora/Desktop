/********************************************************************************
** Form generated from reading UI file 'clock.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOCK_H
#define UI_CLOCK_H

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
    QWidget *weather;
    QLabel *img;
    QLabel *temperature;
    QLabel *wea;
    QWidget *tomato;
    QLabel *time;
    QLabel *date;

    void setupUi(QWidget *clock)
    {
        if (clock->objectName().isEmpty())
            clock->setObjectName("clock");
        clock->resize(570, 480);
        QFont font;
        font.setFamilies({QString::fromUtf8("HarmonyOS Sans SC")});
        font.setPointSize(16);
        clock->setFont(font);
        clock->setWindowOpacity(0.000000000000000);
        sen = new QTextBrowser(clock);
        sen->setObjectName("sen");
        sen->setGeometry(QRect(10, 320, 550, 150));
        weather = new QWidget(clock);
        weather->setObjectName("weather");
        weather->setGeometry(QRect(10, 170, 150, 150));
        img = new QLabel(weather);
        img->setObjectName("img");
        img->setGeometry(QRect(10, 10, 60, 60));
        img->setStyleSheet(QString::fromUtf8(""));
        img->setScaledContents(true);
        temperature = new QLabel(weather);
        temperature->setObjectName("temperature");
        temperature->setGeometry(QRect(80, 10, 60, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HarmonyOS Sans SC")});
        font1.setPointSize(20);
        font1.setBold(false);
        temperature->setFont(font1);
        temperature->setStyleSheet(QString::fromUtf8(""));
        wea = new QLabel(weather);
        wea->setObjectName("wea");
        wea->setGeometry(QRect(10, 80, 130, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("HarmonyOS Sans SC")});
        font2.setPointSize(24);
        font2.setBold(true);
        wea->setFont(font2);
        tomato = new QWidget(clock);
        tomato->setObjectName("tomato");
        tomato->setGeometry(QRect(170, 170, 390, 150));
        time = new QLabel(clock);
        time->setObjectName("time");
        time->setGeometry(QRect(120, 0, 330, 90));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("HarmonyOS Sans SC Black")});
        font3.setPointSize(35);
        font3.setBold(true);
        time->setFont(font3);
        time->setTextFormat(Qt::PlainText);
        date = new QLabel(clock);
        date->setObjectName("date");
        date->setGeometry(QRect(120, 80, 330, 90));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("HarmonyOS Sans SC Black")});
        font4.setPointSize(32);
        font4.setBold(true);
        date->setFont(font4);
        date->setTextFormat(Qt::PlainText);

        retranslateUi(clock);

        QMetaObject::connectSlotsByName(clock);
    } // setupUi

    void retranslateUi(QWidget *clock)
    {
        clock->setWindowTitle(QCoreApplication::translate("clock", "time", nullptr));
        img->setText(QString());
        temperature->setText(QCoreApplication::translate("clock", "16\342\204\203", nullptr));
        wea->setText(QCoreApplication::translate("clock", "\345\244\232\344\272\221", nullptr));
        time->setText(QCoreApplication::translate("clock", "00 : 00: 00", nullptr));
        date->setText(QCoreApplication::translate("clock", "1900/1/1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clock: public Ui_clock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOCK_H
