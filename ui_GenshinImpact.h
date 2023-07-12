/********************************************************************************
** Form generated from reading UI file 'genshinimpactUToCVJ.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GENSHINIMPACTUTOCVJ_H
#define GENSHINIMPACTUTOCVJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GenshinImpact
{
public:
    QLabel *wt;
    QLabel *cangliang;
    QLabel *tili;
    QLabel *tili_lb;
    QProgressBar *tili_bar;
    QProgressBar *wt_bar;
    QLabel *wt_lb;
    QProgressBar *canliang_bar;
    QLabel *canliang_lb;

    void setupUi(QWidget *GenshinImpact)
    {
        if (GenshinImpact->objectName().isEmpty())
            GenshinImpact->setObjectName("GenshinImpact");
        GenshinImpact->resize(550, 400);
        QFont font;
        font.setFamilies({QString::fromUtf8("HarmonyOS Sans SC")});
        font.setBold(true);
        GenshinImpact->setFont(font);
        wt = new QLabel(GenshinImpact);
        wt->setObjectName("wt");
        wt->setGeometry(QRect(135, 150, 80, 80));
        wt->setPixmap(QPixmap(QString::fromUtf8(":/assets/wt.png")));
        cangliang = new QLabel(GenshinImpact);
        cangliang->setObjectName("cangliang");
        cangliang->setGeometry(QRect(135, 250, 80, 80));
        cangliang->setPixmap(QPixmap(QString::fromUtf8(":/assets/canliang.png")));
        tili = new QLabel(GenshinImpact);
        tili->setObjectName("tili");
        tili->setGeometry(QRect(135, 50, 80, 80));
        tili->setPixmap(QPixmap(QString::fromUtf8(":/assets/tili.png")));
        tili_lb = new QLabel(GenshinImpact);
        tili_lb->setObjectName("tili_lb");
        tili_lb->setGeometry(QRect(215, 50, 200, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("HarmonyOS Sans SC")});
        font1.setPointSize(24);
        font1.setBold(true);
        tili_lb->setFont(font1);
        tili_bar = new QProgressBar(GenshinImpact);
        tili_bar->setObjectName("tili_bar");
        tili_bar->setGeometry(QRect(215, 100, 200, 30));
        tili_bar->setValue(45);
        tili_bar->setTextVisible(false);
        wt_bar = new QProgressBar(GenshinImpact);
        wt_bar->setObjectName("wt_bar");
        wt_bar->setGeometry(QRect(215, 200, 200, 30));
        wt_bar->setValue(45);
        wt_bar->setTextVisible(false);
        wt_lb = new QLabel(GenshinImpact);
        wt_lb->setObjectName("wt_lb");
        wt_lb->setGeometry(QRect(215, 150, 200, 50));
        wt_lb->setFont(font1);
        canliang_bar = new QProgressBar(GenshinImpact);
        canliang_bar->setObjectName("canliang_bar");
        canliang_bar->setGeometry(QRect(215, 300, 200, 30));
        canliang_bar->setValue(45);
        canliang_bar->setTextVisible(false);
        canliang_lb = new QLabel(GenshinImpact);
        canliang_lb->setObjectName("canliang_lb");
        canliang_lb->setGeometry(QRect(215, 250, 200, 50));
        canliang_lb->setFont(font1);

        retranslateUi(GenshinImpact);

        QMetaObject::connectSlotsByName(GenshinImpact);
    } // setupUi

    void retranslateUi(QWidget *GenshinImpact)
    {
        GenshinImpact->setWindowTitle(QCoreApplication::translate("GenshinImpact", "GenshinImpact", nullptr));
        wt->setText(QString());
        cangliang->setText(QString());
        tili->setText(QString());
        tili_lb->setText(QCoreApplication::translate("GenshinImpact", "<html><head/><body><p align=\"center\">160/160</p></body></html>", nullptr));
        wt_lb->setText(QCoreApplication::translate("GenshinImpact", "<html><head/><body><p align=\"center\">4/4</p></body></html>", nullptr));
        canliang_lb->setText(QCoreApplication::translate("GenshinImpact", "<html><head/><body><p align=\"center\">\344\270\215\345\217\257\347\224\250</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GenshinImpact: public Ui_GenshinImpact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GENSHINIMPACTUTOCVJ_H
