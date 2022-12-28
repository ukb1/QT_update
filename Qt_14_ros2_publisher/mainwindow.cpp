#include "mainwindow.h"

// window::window(int argc, char** argv): QWidget(nullptr)
// {
//     send_button = new QPushButton("send", this);
//     send_button->move(100,100);
//    connect(send_button,  &QPushButton::clicked, this, [&]() { ros_node->qt_callback(); });
// }




window::window(): QWidget(nullptr)
{
    send_button = new QPushButton("send", this);
    send_button->move(100,100);
   connect(send_button,  &QPushButton::clicked, this, [&]() { ros_node->qt_callback(); });
}

