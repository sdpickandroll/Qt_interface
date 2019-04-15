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

class q_bool : public QObject
{
    Q_OBJECT
    Q_PROPERTY( bool value READ getValue WRITE setValue NOTIFY valueChanged )
public:
    explicit q_bool( QObject* parent = nullptr ) :
        QObject{ parent }, i_{ 0 } {}
    virtual ~q_bool() {}

    int getValue() const { return i_; }
public slots:
    void setValue( bool value )
    {
        if ( value != i_ ) {
            i_ = value;
            emit valueChanged( i_ );
        }
    }
signals:
    void valueChanged( bool value );
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
    void readplatformbat();
    void readplatformforward();
    void readplatformbackward();
    void readplatformcw();
    void readplatformccw();


private slots:

    void on_debugButton_clicked();

private:
    Ui::MainWindow *ui;

    q_num *platform_bat;
    q_bool *platform_forward;
    q_bool *platform_backward;
    q_bool *platform_cw;
    q_bool *platform_ccw;
};

#endif // MAINWINDOW_H
