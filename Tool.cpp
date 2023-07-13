#include "Tool.h"

void press(WORD key) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SendInput(1, &input, sizeof(INPUT));
}

void release(WORD key) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SendInput(1, &input, sizeof(INPUT));
}

Tool::Tool(Json::Value root, QWidget *parent)
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

    // 加载QPushButton
    // 获取json信息
    Json::Value tools = root["tools"];
    int numApplication = tools["applications"].size();
    if (numApplication > 6) {
        QMessageBox::warning(nullptr, "Oops", "☹️ 设置图标过多, 请删除一些后再重试 (最多6项)");
        std::exit(EXIT_FAILURE);
    }
    Json::Value applications = tools["applications"];

    // 定义样式 550, 400
    const int style[6][2] = {
            {100, 0},
            {260, 0},
            {400, 0},
            {100, 120},
            {260, 120},
            {400, 120}
    };
    // 创建
    for (int i = 0; i < numApplication; ++i) {
        Json::Value application = applications[i];
        std::string icon    = application["icon"].asString(),
                    name    = application["name"].asString();
        const char *commond = application["commond"].asCString();
        Json::Value key = application["key"];

        // 新建QPushButton
        auto *bt = new QPushButton;
        bt->setParent(this);
        bt->setGeometry(style[i][0], style[i][1], 80, 80);
        bt->show();

        if ((~icon.empty()) && (~name.empty())) {
            // icon, name 不为空
            QString str = QString::fromStdString("border-image: url(" + icon + ")");
            bt->setStyleSheet(str);
            bt->setWhatsThis(QString::fromStdString(name));
            if ((commond == nullptr) && (key.isNull())) {
                QMessageBox::warning(nullptr, "Oops", "☹️ 加载命令/键为空, 请检查config.json文件");
                std::exit(EXIT_FAILURE);
            } else {
                // 链接QPushbutton和信号
                connect(bt, &QPushButton::clicked, this, [=]() {
                    if (~key.isNull()) {
                        std::vector<WORD> k_v;
                        for (int i; i < key.size(); ++i) {
                            WORD k = key[i].asInt();
                            k_v.push_back(k);
                        }
                        // 依次按下并释放
                        for (int i; i < k_v.size(); ++i) {
                            press(k_v[i]);
                        }
                        for (int i; i < k_v.size(); ++i) {
                            release(k_v[i]);
                        }
                    }
                    system(commond);
                });
            }
        } else {
            QMessageBox::warning(nullptr, "Oops", "☹️ 加载命令/键为空, 请检查config.json文件");
            std::exit(EXIT_FAILURE);
        }
    }
}

Tool::~Tool() {
    delete ui;
}
