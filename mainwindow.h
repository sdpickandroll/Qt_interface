#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QDebug>
#include <QObject>

namespace Ui {
class MainWindow;
}

class q_num : public QObject
{
    Q_OBJECT
    Q_PROPERTY( int value READ getValue WRITE setValue NOTIFY valueChanged )
public:
    explicit q_num( QObject* parent = nullptr ) :
        QObject{ parent }, i_{ 0 } {}
    virtual ~q_num() {}

    int getValue() const { return i_; }
public slots:
    void setValue( int value )
    {
        if ( value != i_ ) {
            i_ = value;
            emit valueChanged( i_ );
        }
    }
signals:
    void valueChanged( int value );
private:
    int i_;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void readlipo();
    void readlipo2();
    void readplatform();
    void readinputstate();


private slots:

    void on_debugButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemWatcher *lipo_watcher;
    QFileSystemWatcher *platform_watcher;
    QFileSystemWatcher *input_state_watcher;

    q_num *lipo_num;
};

#endif // MAINWINDOW_H
