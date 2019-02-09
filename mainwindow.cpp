#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileSystemWatcher>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lipo_watcher = new QFileSystemWatcher(this);
    lipo_watcher->addPath("C:/Users/glach/Desktop/griffins_best_effort/resources/data/lipo_levels.txt");
    connect(lipo_watcher, SIGNAL(fileChanged(QString)), this, SLOT(readlipo()));

    platform_watcher = new QFileSystemWatcher(this);
    platform_watcher->addPath("C:/Users/glach/Desktop/griffins_best_effort/resources/data/platform_levels.txt");
    connect(platform_watcher, SIGNAL(fileChanged(QString)), this, SLOT(readplatform()));

    input_state_watcher = new QFileSystemWatcher(this);
    input_state_watcher->addPath("C:/Users/glach/Desktop/griffins_best_effort/resources/data/input_state.txt");
    connect(input_state_watcher, SIGNAL(fileChanged(QString)), this, SLOT(readinputstate()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readlipo()
{
    QFile file("C:/Users/glach/Desktop/griffins_best_effort/resources/data/lipo_levels.txt");
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
    QFile file("C:/Users/glach/Desktop/griffins_best_effort/resources/data/platform_levels.txt");
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
    QFile file("C:/Users/glach/Desktop/griffins_best_effort/resources/data/input_state.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "couldnt read file";
    }
    QTextStream in(&file);
    QString text = in.readAll();
    qDebug() << text;

    QRegExp rx("forward: |\\nbackward: |\\ncw: |\\nccw: ");
    QStringList state_list = text.split(rx, QString::SkipEmptyParts);

    QPixmap white("C:/Users/glach/Desktop/griffins_best_effort/resources/static_resources/white.jpg");
    QPixmap up_arrow("C:/Users/glach/Desktop/griffins_best_effort/resources/static_resources/up.jpg");
    QPixmap down_arrow("C:/Users/glach/Desktop/griffins_best_effort/resources/static_resources/down.jpg");
    QPixmap clockwise("C:/Users/glach/Desktop/griffins_best_effort/resources/static_resources/cw.jpg");
    QPixmap counter_clockwise("C:/Users/glach/Desktop/griffins_best_effort/resources/static_resources/ccw.jpg");

    if (state_list[0] == "1"){
        ui->up_arrow_label->setPixmap(up_arrow.scaled(50, 50, Qt::KeepAspectRatio));
    } else {
        ui->up_arrow_label->setPixmap(white.scaled(50, 50, Qt::KeepAspectRatio));
    }
    if (state_list[1] == "1"){
        ui->down_arrow_label->setPixmap(down_arrow.scaled(50, 50, Qt::KeepAspectRatio));
    } else {
        ui->down_arrow_label->setPixmap(white.scaled(50, 50, Qt::KeepAspectRatio));
    }
    if (state_list[2] == "1"){
        ui->turning_label->setPixmap(clockwise.scaled(100, 100, Qt::KeepAspectRatio));
    } else if (state_list[3] == "1"){
        ui->turning_label->setPixmap(counter_clockwise.scaled(100, 100, Qt::KeepAspectRatio));
    } else{
        ui->turning_label->setPixmap(white.scaled(100, 100, Qt::KeepAspectRatio));
    }



    file.close();
}

