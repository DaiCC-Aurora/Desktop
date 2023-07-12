#include "ui_Tool.h"
#include <QMessageBox>
#include <QFile>
#include <Windows.h>

QT_BEGIN_NAMESPACE
namespace Ui {}
QT_BEGIN_NAMESPACE

class Tool : public QWidget {
    Q_OBJECT
public:
    explicit Tool(QWidget *parent = nullptr);
    ~Tool() override;

private:
    Ui::Tool *ui;
};