#pragma once
#include "includes.h"
#include "ui_clock.h"

QT_BEGIN_NAMESPACE
namespace Ui {}
QT_END_NAMESPACE

class Clock : public QWidget {
    Q_OBJECT

public:
    explicit Clock(Json::Value& root, QWidget *parent = nullptr);
    ~Clock() override;

private:
    Ui::clock *ui;
    QTimer *timer, *timer_wea;

    void get_weather(Json::Value root);
    void update_time();
    void get_sen();
};