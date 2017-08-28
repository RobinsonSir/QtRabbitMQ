#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qrabbitmq.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showMsg(QString msg);
    void on_sendBtn_clicked();
    void on_connBtn_clicked();

private:
    Ui::MainWindow *ui;

    QRabbitMQ *m_rabbitClient;
};

#endif // MAINWINDOW_H
