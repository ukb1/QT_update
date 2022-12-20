#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtGui>
#include <QtCore>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>



//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* window   = new QWidget(this);
//    QPushButton* button1 = new QPushButton("button1", this);
//    QPushButton* button2 = new QPushButton("button2", this);
//    QPushButton* button3 = new QPushButton("button3", this);
//    QPushButton* button4 = new QPushButton("button4", this);
//    QHBoxLayout* h_box   = new QHBoxLayout;
    QGridLayout *layout   = new QGridLayout(this);
    QLabel* label = new QLabel;
    QLineEdit* line = new QLineEdit;
//    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
