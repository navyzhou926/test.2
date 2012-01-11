#ifndef CONTROLWIN_H
#define CONTROLWIN_H

#include <QPushButton>
#include <QWidget>
#include <QProcess>
#include <QTcpSocket>
#include <QUdpSocket>

class ControlWin : public QWidget
{
    Q_OBJECT
public:
    explicit ControlWin(QWidget *parent = 0);
    void OnON();
    void OnOFF();

    void exe_a();

    QProcess *disProcess;
    QProcess *disProcess_exe;
    //QProcess *disProcess_a;
    QUdpSocket *udpSocket;
    int flag;


signals:

public slots:

    void slotready();
    void slotSendMsg();


};

#endif // CONTROLWIN_H
