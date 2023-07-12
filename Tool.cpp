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
