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
    QStringList debug_list;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void readlipo();
    void readplatform();
    void readinputstate();


private slots:

    void on_debugButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemWatcher *lipo_watcher;
    QFileSystemWatcher *platform_watcher;
    QFileSystemWatcher *input_state_watcher;
};

#endif // MAINWINDOW_H
