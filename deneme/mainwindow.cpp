#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << ui->lineEdit->displayText();
     ui->lineEdit->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

