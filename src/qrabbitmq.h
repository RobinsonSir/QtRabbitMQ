#ifndef QRABBITMQ_H
#define QRABBITMQ_H

#include <QObject>
#include <QCoreApplication>
#include <QStringList>
#include <QDebug>

#include "QAMQP/qamqpclient.h"
#include "QAMQP/qamqpexchange.h"
#include "QAMQP/qamqpqueue.h"

class QRabbitMQ : public QObject
{
    Q_OBJECT
public:
    explicit QRabbitMQ(QObject *parent = 0);

    void setServerParam(const QString &ip, int port);
    void setRabbitClientParam(const QString &routingKey, const QStringList &bindingKeyList);

    void sendMsg(const QString &msg);

signals:
    void msgSig(QString msg);

public slots:
    void start();

private slots:
    void clientConnected();
    void exchangeDeclared();
    void queueDeclared();
    void messageReceived();

private:
    QAmqpClient m_client;

    QString m_routingKey;

    //One client can bind many keys
    QStringList m_bindingKeyList;

    QString m_serverIP;
    int m_serverPort;

    QString m_exchangerName;

};

#endif // QRABBITMQ_H
