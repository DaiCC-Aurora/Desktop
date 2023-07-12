#include "Tool.h"

Tool::Tool(QWidget *parent)
    : QWidget(parent), ui(new Ui::Tool()) {
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
}

Tool::~Tool() {
    delete ui;
}