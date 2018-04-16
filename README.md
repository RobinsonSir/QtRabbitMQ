### Run example
RabbitClient.exe
Double click RabbitClient.exe in ReleaseFiles folder to run it, you can run two clients to talk to each other.

### How to use 
1, You should copy qamqp.dll to App.exe folder(bin folder) from ReleaseFiles folder when you run project in Qt IDE.
2, qamqp.dll compiled by Qt5.3.1. (Gets it from https://github.com/RobinsonSir/qamqp)


### RabbitMQ简介
  MQ全称为Message Queue, 消息队列（MQ）是一种应用程序对应用程序的通信方法。RabbitMQ简单理解，可以将它比喻为邮局，人们给邮局投递信件，邮局将信件派送给收件人。
  
具体工作原理大家参考RabbitMQ官网：
http://www.rabbitmq.com/

### Qt环境
(1)，Qt5.3.1，系统win7   
(2)，RabbitMQ server(官网下载安装：http://www.rabbitmq.com/download.html)

本文实现的为RabbitMQ 客户端，首先需要自行安装RabbitMQ server。

此客户端使用的RabbitMQ的Routing模式（type=direct），参考官网：
http://www.rabbitmq.com/getstarted.html

![RabbitMQ](http://img.blog.csdn.net/20170829145936444?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvemJjNDE1NzY2MzMx/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

程序截图：
![](http://img.blog.csdn.net/20170829140721194?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvemJjNDE1NzY2MzMx/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

注意两个客户端的bindingkey与routingkey 设置：

![](http://img.blog.csdn.net/20170829140039196?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvemJjNDE1NzY2MzMx/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

说明：   
1，serverIP 为RabbitMQ server 的ip, port默认为5672。
2，connect之后 两个客户端就可以互发信息了。

怎么启动server 官网有这么句话：Then just run the installer, rabbitmq-server-3.6.11.exe. It will set RabbitMQ up and running as a service, with a default configuration.

安装完毕，应该是会自动启动RabbitMQ server服务的。

RabbitMQ在15672端口上有个后台管理网页，默认登录名称与密码都为guest，在这里可已查看客户端与RabbitMQ server的连接情况。

![](http://img.blog.csdn.net/20170829140002600?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvemJjNDE1NzY2MzMx/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

参考：http://www.rabbitmq.com/install-windows.html 


本文代码参考：https://github.com/RobinsonSir/qamqp

CSDN: http://blog.csdn.net/zbc415766331/article/details/77659204
