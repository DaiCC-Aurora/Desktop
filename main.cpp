#include "includes.h"
#include "clock.h"
#include "GenshinImpact.h"
#include "Tool.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // test begin
    httplib::Client cli("http://api.seniverse.com");
    auto r = cli.Get("/v3/weather/now.json?key=Sv8nxmtsw4SjXQGbT&location=shaoguan");
    // test end

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
        auto *tool = new Tool(root, nullptr);
        tool->show();
    }
    // 时钟 启动
    if (time_activated) {
        auto *clock = new Clock(root, nullptr);
        clock->show();
    }

	return QApplication::exec();
}

/*
 * 接口地址
https://api.seniverse.com/v3/weather/now.json?key=your_api_key&location=beijing&language=zh-Hans&unit=c

请求参数说明
参数名称	类型	默认值	必填	备注
key	String	无	是	你的 API 密钥
location	Location	无	是	所查询的位置
language	Language	zh-Hans	否	语言
unit	Unit	c	否	单位
 Sv8nxmtsw4SjXQGbT
 */