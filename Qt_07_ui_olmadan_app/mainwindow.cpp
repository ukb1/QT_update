#include "mainwindow.h"
//#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
{
//    h_box->addWidget(button1);
//    h_box->addWidget(button2);
//    h_box->addWidget(button3);
//    h_box->addWidget(button4);

    layout->addWidget(label, 0,0);
    layout->addWidget(line, 0,1);
    window->setLayout(layout);
//    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
//    delete ui;
}

