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
    ui->sen->setStyleSheet("font-size: 18pt;background:transparent;border-width:0;border-style:outset;");
    ui->sen->setDisabled(true);

    // 定时器设置
    this->timer->start(250);
    connect(this->timer, &QTimer::timeout, this, &Clock::update_time);

    this->timer_wea->start(300000);
    connect(this->timer_wea, &QTimer::timeout, this, [=]() {
        this->get_weather(root);
        this->get_sen();
    });

    // 更改部分样式
    ui->time->setAlignment(Qt::AlignCenter);
    ui->date->setAlignment(Qt::AlignCenter);
    ui->wea->setAlignment(Qt::AlignCenter);


    // 首次初始化
    this->get_weather(root);
    this->get_sen();
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

    Json::CharReaderBuilder builder;
    Json::Value res;
    std::string err;

    if (response && response->status == 200) {
        std::istringstream input(response->body);
        if (Json::parseFromStream(builder, input, &res, &err)) {
            // ["results"][0]["now"]
            Json::Value js_now = res["results"][0]["now"];

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
            QMessageBox::warning(nullptr, "Oops", "☹️ 天气获取失败, 请检查网络及配置\nError" + QString::fromStdString(err));
            std::exit(EXIT_FAILURE);
        }
    } else {
        QMessageBox::warning(nullptr, "Oops", "☹️ 天气获取失败, 请检查网络及配置\nError" + QString::fromStdString(err));
        std::exit(EXIT_FAILURE);
    }
}

void Clock::update_time() {
    time_t time_now = time(nullptr);
    char temp_time[48],
         temp_date[48];
    strftime(temp_time, sizeof(temp_time), "%H : %M : %S", localtime(&time_now));
    strftime(temp_date, sizeof(temp_date), "%Y / %m / %d", localtime(&time_now));

    ui->time->setText(temp_time);
    ui->date->setText(temp_date);
}

void Clock::get_sen() {
    QFile file("./assets/text._res");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Oops", "无法加载text._res, 请重试");
        std::exit(EXIT_FAILURE);
    }
    QTextStream in(&file);
    std::vector<QString> lines;
    while (!in.atEnd()) {
        QString line = in.readLine();
        lines.push_back(line);
    }
    file.close();

    auto now = std::time(nullptr);
    std::tm tm = *std::localtime(&now);
    int day = tm.tm_yday;
    ui->sen->setText(lines[day]);
}
