#include "qrabbitmq.h"

QRabbitMQ::QRabbitMQ(QObject *parent) :
    QObject(parent)
{
    m_exchangerName = "direct_exchanger";
}

void QRabbitMQ::start()
{
    connect(&m_client, SIGNAL(connected()), this, SLOT(clientConnected()));

    //Localhost
    //m_client.connectToHost();

    m_client.connectToHost(QHostAddress(m_serverIP), m_serverPort);
}

void QRabbitMQ::clientConnected()
{
    QAmqpExchange *exchange = m_client.createExchange(m_exchangerName);
    connect(exchange, SIGNAL(declared()), this, SLOT(exchangeDeclared()));
    exchange->declare(QAmqpExchange::Direct);

    qDebug() << "RabbitMQ connect to server ok";
}

void QRabbitMQ::exchangeDeclared()
{
    QAmqpQueue *temporaryQueue = m_client.createQueue();
    connect(temporaryQueue, SIGNAL(declared()), this, SLOT(queueDeclared()));
    connect(temporaryQueue, SIGNAL(messageReceived()), this, SLOT(messageReceived()));
    temporaryQueue->declare(QAmqpQueue::Exclusive);
}

void QRabbitMQ::queueDeclared()
{
    QAmqpQueue *temporaryQueue = qobject_cast<QAmqpQueue*>(sender());
    if (!temporaryQueue)
        return;

    // start consuming
    temporaryQueue->consume(QAmqpQueue::coNoAck);

    //Bind keys
    foreach (QString severity, m_bindingKeyList)
        temporaryQueue->bind(m_exchangerName, severity);

    qDebug() << " [*] Waiting for message.";
}

void QRabbitMQ::messageReceived()
{
    QAmqpQueue *temporaryQueue = qobject_cast<QAmqpQueue*>(sender());
    if (!temporaryQueue)
        return;

    QAmqpMessage message = temporaryQueue->dequeue();

    QString msg = "Recv: [x] " + message.routingKey() + ":" + message.payload();

    qDebug() << msg;

    emit msgSig(msg);
}

void QRabbitMQ::sendMsg(const QString &msg)
{
    QAmqpExchange *exchange = m_client.createExchange(m_exchangerName);

    exchange->publish(msg, m_routingKey);
}

void QRabbitMQ::setServerParam(const QString &ip, int port)
{
    m_serverIP = ip;
    m_serverPort = port;
}

void QRabbitMQ::setRabbitClientParam(const QString &routingKey, const QStringList &bindingKeyList)
{
    m_routingKey = routingKey;
    m_bindingKeyList = bindingKeyList;
}
