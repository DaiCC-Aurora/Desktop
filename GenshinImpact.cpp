#include "GenshinImpact.h"

GenshinImpact::GenshinImpact(QWidget *parent)
    : QWidget(parent), ui(new Ui::GenshinImpact()) {
    ui->setupUi(this);

    // 设置背景
    ui->tili->setPixmap(QPixmap::fromImage(QImage("./assets/tili.png")));
    ui->wt->setPixmap(QPixmap::fromImage(QImage("./assets/wt.png")));
    ui->cangliang->setPixmap(QPixmap::fromImage(QImage("./assets/canliang.png")));

    // 设置样式
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
    int swidth = GetSystemMetrics(SM_CXSCREEN);
    this->move(swidth - this->width(), 0);

    // 设置变量范围
    ui->tili_bar->setRange(0, 160);
    ui->wt_bar->setRange(0, 4);

    // 设置定时器
    this->timer = new QTimer(this);
    this->timer->start(500);
    connect(this->timer, &QTimer::timeout, this, &GenshinImpact::update_data);
}

void GenshinImpact::update_data() {
    // TODO: 获取树脂数量, 显示
    // TODO: 获取每日委托数量, 显示
    // TODO: 获取参量质变仪参数, 显示
}

GenshinImpact::~GenshinImpact() {
    delete ui;
}
