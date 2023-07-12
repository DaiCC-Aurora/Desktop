#include "ui_Tool.h"
#include <QMessageBox>
#include <QFile>
#include <Windows.h>
#include <jsoncpp.h>

QT_BEGIN_NAMESPACE
namespace Ui {}
QT_BEGIN_NAMESPACE

/*
 * @brief 按下一个键
 * @param key - 键
 */
void press(WORD key);

/*
 * @brief 放开一个键
 * @param key - 键
 */
void release(WORD key);

class Tool : public QWidget {
    Q_OBJECT
public:
    explicit Tool(QWidget *parent = nullptr);
    ~Tool() override;

private:
    Ui::Tool *ui;
};
