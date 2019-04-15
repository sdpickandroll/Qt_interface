#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QDialog>
#include <QFileSystemWatcher>
#include <QDebug>

namespace Ui {
class DebugWindow;
}

class DebugWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = nullptr);
    ~DebugWindow();

private slots:
    void on_debugclose_clicked();
    void readdebug();

private:
    Ui::DebugWindow *ui;

    QFileSystemWatcher *debug_watcher;
};

#endif // DEBUGWINDOW_H
