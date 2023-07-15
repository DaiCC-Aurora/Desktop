#pragma once
#include "includes.h"
#include "ui_GenshinImpact.h"

QT_BEGIN_NAMESPACE
namespace Ui {}
QT_END_NAMESPACE

class GenshinImpact : public QWidget {
    Q_OBJECT
public:
    explicit GenshinImpact(QWidget *parent = nullptr);
    ~GenshinImpact() override;

private:
    Ui::GenshinImpact *ui;
    QTimer *timer;
    int tili = 0, wt = 0;
    bool canliang = false;

    void update_data();
};