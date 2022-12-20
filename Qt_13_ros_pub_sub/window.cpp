#include "window.h"
#include "./ui_window.h"

window::window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window)
{
    rosnode = new rosNode(this);
    ui->setupUi(this);
    connect(rosnode, SIGNAL(startChanged(int)), this, SLOT(labelChanged(int)));
}

window::~window()
{
    delete ui;
}


void window::labelChanged(int value)
{
    ui->value_line->setText(QString::number(value));
}

void window::on_start_button_clicked()
{
    rosnode->stop = true;
    ui->textEdit->setText("<b>Started...</b>");
    rosnode->start();
}

void window::on_stop_button_clicked()
{
    rosnode->stop = false;
    ui->textEdit->setText("<b>Stoped...</b>");
}

void window::on_reset_button_clicked()
{
    if(rosnode->value!=0)
    {
        QMessageBox::information(this, "Reset", "values ​​are reset");
        rosnode->value = 0;
        ui->textEdit->setText("<b>Reset...</b>");
        rosnode->stop = false;
    }
}

void window::on_up_button_clicked()
{
    qDebug("UP");
}

void window::on_down_button_clicked()
{
    qDebug("DOWN");
}

void window::on_left_button_clicked()
{
    qDebug("LEFT");
}

void window::on_right_button_clicked()
{
    qDebug("RIGHT");
}

void window::on_cancel_button_clicked()
{
    QMessageBox::warning(this, "EXİT", "The data will be deleted and the application will be closed.");
}
