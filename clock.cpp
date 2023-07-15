#include "clock.h"

Clock::Clock(Json::Value& root, QWidget *parent)
    : QWidget(parent), ui(new Ui::clock) {
    ui->setupUi(this);

    // 加载QSS
    QString qss;
    QFile qssFile("./assets/style.qss");
    qssFile.open(QFile::ReadOnly);
    if (qssFile.isOpen()) {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    } else {
        QMessageBox::warning(nullptr, "Oops", "☹️ 加载样式表失败, 请检查资源完整");
        std::exit(EXIT_FAILURE);
    }

    // 设置窗口
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnBottomHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(0.75);
    int swidth  = GetSystemMetrics(SM_CXSCREEN);
    this->move(swidth - this->width(), 340);

    // 定时器设置
    this->timer = new QTimer(this);
    this->timer->start(500);
    connect(this->timer, &QTimer::timeout, this, &Clock::update_time);

    this->timer_wea = new QTimer(this);
    this->timer->start(300000);
    connect(this->timer_wea, &QTimer::timeout, this, [=]() {
        get_weather(root);
    });
}

Clock::~Clock() {
    delete ui;
}

std::string Clock::get_weather(Json::Value root) {
    return "";
}

void Clock::update_time() {

}

void Clock::get_sen() {

}
