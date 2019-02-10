#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void readlipo();
    void readplatform();
    void readinputstate();
//    QStringList readdebug(QStringList debug_list);

private slots:
    void on_debugButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemWatcher *lipo_watcher;
    QFileSystemWatcher *platform_watcher;
    QFileSystemWatcher *input_state_watcher;
    QFileSystemWatcher *debug_watcher;
//    static QStringList the_debug_list;

};

#endif // MAINWINDOW_H
