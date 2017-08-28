#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_rabbitClient = new QRabbitMQ(this);

    connect(m_rabbitClient, SIGNAL(msgSig(QString)),
            this, SLOT(showMsg(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_rabbitClient;
}

void MainWindow::showMsg(QString msg)
{
    ui->textBrowser->append(msg);
}

void MainWindow::on_sendBtn_clicked()
{
    m_rabbitClient->sendMsg(ui->lineEdit->text());
    ui->textBrowser->append("Send: " + ui->lineEdit->text());
}

void MainWindow::on_connBtn_clicked()
{
    m_rabbitClient->setServerParam(ui->serverIP->text(), ui->serverPort->value());
    m_rabbitClient->setRabbitClientParam(ui->routingKey->text(), ui->bindingKey->text().split(";"));

    m_rabbitClient->start();

    ui->connBtn->setText("DisConn");
}
