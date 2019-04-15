#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "debugwindow.h"
#include "QObject"
#include <QFileSystemWatcher>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    platform_bat = new q_num(this);
    connect(platform_bat, SIGNAL(valueChanged(int)), this, SLOT(readplatformbat()));
    platform_bat->setValue(100);

    platform_forward = new q_bool(this);
    connect(platform_forward, SIGNAL(valueChanged(bool)), this, SLOT(readplatformforward()));
    platform_forward->setValue(false);
    ui->up_arrow_label->hide();

    platform_backward = new q_bool(this);
    connect(platform_backward, SIGNAL(valueChanged(bool)), this, SLOT(readplatformbackward()));
    platform_backward->setValue(false);
    ui->down_arrow_label->hide();

    platform_cw = new q_bool(this);
    connect(platform_cw, SIGNAL(valueChanged(bool)), this, SLOT(readplatformcw()));
    platform_cw->setValue(false);
    ui->turning_label->hide();

    platform_ccw = new q_bool(this);
    connect(platform_ccw, SIGNAL(valueChanged(bool)), this, SLOT(readplatformccw()));
    platform_ccw->setValue(false);
    ui->turning_label->hide();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readplatformbat()
{
    ui->progressBar_2->setValue(platform_bat->getValue());
}

void MainWindow::readplatformforward()
{
    QPixmap up_arrow("../Qt_interface/resources/static_resources/up.jpg");
    bool state = platform_forward->getValue();
    if (state == true){
        ui->up_arrow_label->show();
        ui->up_arrow_label->setPixmap(up_arrow.scaled(ui->up_arrow_label->width(), ui->up_arrow_label->height(), Qt::KeepAspectRatio));
    } else {
        ui->up_arrow_label->hide();
    }
}

void MainWindow::readplatformbackward()
{
    QPixmap down_arrow("../Qt_interface/resources/static_resources/down.jpg");
    bool state = platform_backward->getValue();
    if (state == true){
        ui->down_arrow_label->show();
        ui->down_arrow_label->setPixmap(down_arrow.scaled(ui->down_arrow_label->width(), ui->down_arrow_label->height(), Qt::KeepAspectRatio));
    } else {
        ui->down_arrow_label->hide();
    }
}

void MainWindow::readplatformcw()
{
    QPixmap clockwise("../Qt_interface/resources/static_resources/cw.jpg");
    bool state = platform_cw->getValue();
    if (state == true){
        ui->turning_label->show();
        ui->turning_label->setPixmap(clockwise.scaled(ui->turning_label->width(), ui->turning_label->height(), Qt::KeepAspectRatio));
    } else if (platform_cw->getValue() == false && platform_ccw->getValue() == false) {
        ui->turning_label->hide();
    }
}

void MainWindow::readplatformccw()
{
    QPixmap counter_clockwise("../Qt_interface/resources/static_resources/ccw.jpg");
    bool state = platform_ccw->getValue();
    if (state == true){
        ui->turning_label->show();
        ui->turning_label->setPixmap(counter_clockwise.scaled(ui->turning_label->width(), ui->turning_label->height(), Qt::KeepAspectRatio));
    } else if (platform_cw->getValue() == false && platform_ccw->getValue() == false) {
        ui->turning_label->hide();
    }
}

void MainWindow::on_debugButton_clicked()
{
    DebugWindow debugwindow;
    debugwindow.setModal(true);
    debugwindow.exec();
}
