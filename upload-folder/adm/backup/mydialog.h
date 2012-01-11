#ifndef MYDIALOG_H
#define MYDIALOG_H
#include "ui_mydialog.h"
#include <QDialog>
#include <QLabel>
#include <QLCDNumber>
#include <QString>
//#include <QTNetwork/QTcpSocket>
#include <QTextBrowser>
#include <QTime>
#include <QFileInfoList>
#include <QFrame>
#include <QWidget>
#include <QProcess>

#if 0
QT_BEGIN_NAMESPACE

//class QTcpServer;
class QTcpSocket;
QT_END_NAMESPACE
#endif


// int paint_pos;
enum direction{LTR, RTL};

/*
class ShowVideo : public QWidget
{
    Q_OBJECT
public:
    explicit ShowVideo(QWidget *parent = 0);
    virtual ~ShowVideo();

public:
    QProcess *mplayerProcess;
    QWidget *render;

signals:

public slots:

};
*/
#if 1
class ShowText: public QWidget
{
    Q_OBJECT
public:
    explicit ShowText(QWidget *parent = 0);
    virtual ~ShowText();

public:
        void setDirection(direction d){dirvalue = d;}
        direction getDiretion(){return dirvalue;}
        void changeContent(const QString &str){contentstr = str;}

private slots:
    void timeoutslot();

signals:

private:
        void paintEvent(QPaintEvent *event);
        direction dirvalue;
        QString contentstr;

public slots:

};
#endif

class MyDialog:public QWidget, public Ui_Form 
{
    Q_OBJECT
    public:
        explicit MyDialog(QWidget *parent = 0);
        #if 0
        void setDirection(direction d){dirvalue = d;}
        direction getDiretion(){return dirvalue;}
        void changeContent(const QString &str){contentstr = str;}
        #endif
        void changeRate(int value);
        void draw(QPainter *painter);
        void sendMsgTime(); 
    private slots:
        void enter();
        void showTime();
        #if 0
        void timeoutslot();
        #endif
        void showPicture();
        void sendMsg();
        void recvMsg();
        void error();
    private:
        void resizeEvent(QResizeEvent *event);
        QString buf;
        int juge;
        #if 0
        void paintEvent(QPaintEvent *event);
        QString contentstr;
        direction dirvalue;
        #endif
        /*QTcpSocket *tcpSocket;*/
        QString anotherstr;
        QLabel *background;
        QLabel *imageLabel;
        QFileInfoList m_fileInfoList;
        QLCDNumber *lcd;
        QLCDNumber *ymdlcd;
        QString *picPath[50];
        QString msgBuffer;
        QTextBrowser *txtB;
        QTime time;
        QProcess *mplayerProcess;
        QWidget *render;
};

class Frame : public QFrame
{
    Q_OBJECT
public:
    explicit Frame(QWidget *parent = 0);

    /*static QString strRoot;*/

    ShowText *text;
    MyDialog *d;

    void init();
    void stop();

signals:

public slots:

};

#endif

