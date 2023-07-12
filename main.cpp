#include <QApplication>
#include "GenshinImpact.h"
#include "Tool.h"
#include <fstream>
#include <json.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 解析 activated 值
    std::ifstream config("config.json");
    Json::Value root;
    if (!config.is_open()) {
        QMessageBox::warning(nullptr, "Oops", "☹️ 无法加载config.json, 请检查资源是否完整");
        std::exit(EXIT_FAILURE);
    }
    config >> root;
    bool    time_activated      =   root["time"]["activated"].asBool(),
            genshin_activated   =   root["Genshin_Impact"]["activated"].asBool(),
            tools_activated  =   root["tools"]["activated"].asBool();

    // 原神 启动
    if (genshin_activated) {
        auto *genshinImpact = new GenshinImpact();
        genshinImpact->show();
    }

    // 工具 启动
    if (tools_activated) {
        auto *tool = new Tool();
        tool->show();
    }
    // TODO: 时钟 启动
    if (time_activated) {

    }

	return QApplication::exec();
}
