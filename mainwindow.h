#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QByteArray>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//    static QStringList debug_list;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots
    void readlipo();
    void readplatform();
    void readinputstate();
//    void readdebug(QStringList debug_list);

    // read pre-formatted QByteArray to the panorama
    void updatepanorama(
        const QByteArray* data,
        const char* format = 0,
        Qt::ImageConversionFlags flags = Qt::AutoColor
    );

private slots:
    void on_debugButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemWatcher *lipo_watcher;
    QFileSystemWatcher *platform_watcher;
    QFileSystemWatcher *input_state_watcher;
    QFileSystemWatcher *debug_watcher;

};

#endif // MAINWINDOW_H
