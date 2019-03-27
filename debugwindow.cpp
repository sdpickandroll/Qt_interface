#include "debugwindow.h"
#include "ui_debugwindow.h"
#include <QFileSystemWatcher>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPixmap>
#include <QDir>

DebugWindow::DebugWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DebugWindow)
{
    ui->setupUi(this);

    debug_watcher = new QFileSystemWatcher(this);
    debug_watcher->addPath("../Qt_interface/resources/data/debug.txt");
    connect(debug_watcher, SIGNAL(fileChanged(QString)), this, SLOT(readdebug()));
}

DebugWindow::~DebugWindow()
{
    delete ui;
}

void DebugWindow::on_debugclose_clicked()
{
    DebugWindow::close();
}

void DebugWindow::readdebug()
{
    qDebug("fuck");
    QFile file("../Qt_interface/resources/data/debug.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "couldnt read file";
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->debugtextbrowser->setText(text);

    file.close();
}
