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
    Json::Value tools = root["tools"];
    int numApplication = tools["application"].size();
    if (numApplication > 6) {
        QMessageBox::warning(nullptr, "Oops", "☹️ 设置图标过多, 请删除一些后再重试 (最多6项)");
        std::exit(EXIT_FAILURE);
    }
    Json::Value applications = tools["application"];
    for (int i = 0; i < numApplication; ++i) {
        Json::Value application = applications[i];
        std::string icon    = application["icon"].asString(),
                    name    = application["name"].asString(),
                    commond = application["commond"].asString(),
                    key     = application["key"].asString();

        // TODO: 新建QPushButton

        if ((~icon.empty()) && (~name.empty())) {
            // icon, name 不为空
            if ((commond.empty()) && key.empty()) {
                QMessageBox::warning(nullptr, "Oops", "☹️ 加载命令/键为空, 请检查config.json文件");
                std::exit(EXIT_FAILURE);
            } else {
                // TODO: 链接QPushbutton和信号
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
