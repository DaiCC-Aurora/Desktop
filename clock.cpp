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
    int swidth  = GetSystemMetrics(SM_CXSCREEN),
        sheight = GetSystemMetrics(SM_CYSCREEN);
    this->move((swidth - this->width()) / 2,
               (sheight - this->height()) / 4
               );

    // 定时器设置
    this->timer = new QTimer(this);
    this->timer->start(500);
    connect(this->timer, &QTimer::timeout, this, &Clock::update_time);

    this->timer_wea = new QTimer(this);
    this->timer->start(300000);
    connect(this->timer_wea, &QTimer::timeout, this, [=]() {
        get_weather(root);
    });

    // 更改部分样式
    ui->time->setAlignment(Qt::AlignCenter);
    ui->date->setAlignment(Qt::AlignCenter);
    ui->wea->setAlignment(Qt::AlignCenter);

    // 首次初始化
    this->update_time();
    this->get_weather(root);
}

Clock::~Clock() {
    delete ui;
}

void Clock::get_weather(Json::Value root) {
    // 合成URL
    Json::Value time = root["time"];
    std::string key         = time["weather_key"].asString(),
                location    = time["location"].asString(),
                language    = time["language"].asString(),
                unit        = time["unit"].asString();
    if (key.empty() || location.empty()) {
        QMessageBox::warning(nullptr, "Oops", "☹️ 天气获取失败, 请检查config.json");
        std::exit(EXIT_FAILURE);
    }

    // 获取数据
    httplib::Client cli("http://api.seniverse.com");
    std::string path = "/v3/weather/now.json?key=" + key + "&location=" + location + "&language=" + language + "&unit=" + unit;
    auto response = cli.Get(path);
    if (response && response->status == 200) {
        Json::Value res = response->body;
        Json::Value result = res[0];
        std::cout << result << std::endl;
        // {"results":[{"location":{"id":"WS2V1N2FZZ77","name":"韶关","country":"CN","path":"韶关,韶关,广东,中国","timezone":"Asia/Shanghai","timezone_offset":"+08:00"},"now":{"text":"多云","code":"4","temperature":"34"},"last_update":"2023-07-15T18:00:00+08:00"}]}
        Json::Value js_now = res["now"];

        QString text = QString::fromStdString(js_now["text"].asString());
        std::string code = js_now["code"].asString();
        QString temperature = QString::fromStdString(js_now["temperature"].asString());

        // 显示到Widget中
        if (unit == "f") {
            ui->temperature->setText(temperature + QString::fromUtf8("℉"));
        } else {
            ui->temperature->setText(temperature + QString::fromUtf8("℃"));
        }
        ui->wea->setText(text);
        QString img_path = "./assets/weather/" + QString::fromStdString(code) + ".png";
        auto *img = new QImage(img_path);
        ui->img->setPixmap(QPixmap::fromImage(*img));

    } else {
        QMessageBox::warning(nullptr, "Oops", "☹️ 天气获取失败, 请检查网络及配置");
        std::exit(EXIT_FAILURE);
    }
}

void Clock::update_time() {

}

void Clock::get_sen() {

}
