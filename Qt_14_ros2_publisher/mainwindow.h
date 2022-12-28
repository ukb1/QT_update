#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include "rosnode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class window; }
QT_END_NAMESPACE

class QPushButton;

class window : public QWidget, public ros_enable
{
    Q_OBJECT

public:
    // window(int argc, char** argv);
    window();

    // ~window();

private:
    QPushButton* send_button;
};

#endif // WINDOW_H
