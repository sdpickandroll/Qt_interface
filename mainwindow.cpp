#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileSystemWatcher>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPixmap>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lipo_watcher = new QFileSystemWatcher(this);
    lipo_watcher->addPath("../Qt_interface/resources/data/lipo_levels.txt");
    connect(lipo_watcher, SIGNAL(fileChanged(QString)), this, SLOT(readlipo()));

    platform_watcher = new QFileSystemWatcher(this);
    platform_watcher->addPath("../Qt_interface/resources/data/platform_levels.txt");
    connect(platform_watcher, SIGNAL(fileChanged(QString)), this, SLOT(readplatform()));

    input_state_watcher = new QFileSystemWatcher(this);
    input_state_watcher->addPath("../Qt_interface/resources/data/input_state.txt");
    connect(input_state_watcher, SIGNAL(fileChanged(QString)), this, SLOT(readinputstate()));

    //placeholder for video
    int video_width = ui->video_label->width();
    int video_height = ui->video_label->height();
    QPixmap ron("../Qt_interface/resources/data/ronny_boi.jpg");
    ui->video_label->setPixmap(ron.scaled(video_width, video_height));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readlipo()
{
    QFile file("../Qt_interface/resources/data/lipo_levels.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "couldnt read file";
    }
    QTextStream in(&file);
    QString text = in.readAll();
    double num = text.toDouble();
    int perc = num * 100;
    ui->progressBar->setValue(perc);

    file.close();
}
void MainWindow::readplatform()
{
    QFile file("../Qt_interface/resources/data/platform_levels.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "couldnt read file";
    }
    QTextStream in(&file);
    QString text = in.readAll();
    double num = text.toDouble();
    int perc = num * 100;
    ui->progressBar_2->setValue(perc);

    file.close();
}
void MainWindow::readinputstate()
{
    QFile file("../Qt_interface/resources/data/input_state.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "couldnt read file";
    }
    QTextStream in(&file);
    QString text = in.readAll();
    qDebug() << text;

    QRegExp rx("forward: |\\nbackward: |\\ncw: |\\nccw: ");
    QStringList state_list = text.split(rx, QString::SkipEmptyParts);

    QPixmap up_arrow("../Qt_interface/resources/static_resources/up.jpg");
    QPixmap down_arrow("../Qt_interface/resources/static_resources/down.jpg");
    QPixmap clockwise("../Qt_interface/resources/static_resources/cw.jpg");
    QPixmap counter_clockwise("../Qt_interface/resources/static_resources/ccw.jpg");

    if (state_list[0] == "1"){
        ui->up_arrow_label->show();
        ui->up_arrow_label->setPixmap(up_arrow.scaled(50, 50, Qt::KeepAspectRatio));
    } else {
        ui->up_arrow_label->hide();
    }
    if (state_list[1] == "1"){
        ui->down_arrow_label->show();
        ui->down_arrow_label->setPixmap(down_arrow.scaled(50, 50, Qt::KeepAspectRatio));
    } else {
        ui->down_arrow_label->hide();
    }
    if (state_list[2] == "1"){
        ui->turning_label->show();
        ui->turning_label->setPixmap(clockwise.scaled(100, 100, Qt::KeepAspectRatio));
    } else if (state_list[3] == "1"){
        ui->turning_label->show();
        ui->turning_label->setPixmap(counter_clockwise.scaled(100, 100, Qt::KeepAspectRatio));
    } else{
        ui->turning_label->hide();
    }



    file.close();
}

