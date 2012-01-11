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

class ShowVideo : public QWidget
{
    Q_OBJECT
public:
    explicit ShowVideo(QWidget *parent = 0);
    virtual ~ShowVideo();

public:
    QProcess *mplayerProcess;
    QWidget *render;
    QProcess *process;

signals:

public slots:
    void lowerMute();

};

class ShowTime: public QWidget
{
    Q_OBJECT
public:
    explicit ShowTime(QWidget *parent = 0);
    virtual ~ShowTime();

public:

private slots:
        void showTime();

signals:

private:
        QLCDNumber *lcd;
        QTime time;

public slots:

};

class ShowDate: public QWidget
{
    Q_OBJECT
public:
    explicit ShowDate(QWidget *parent = 0);
    virtual ~ShowDate();

public:

private slots:
        void showDate();

signals:

private:
        QLCDNumber *ymdlcd;

public slots:

};

class ShowPic: public QWidget
{
    Q_OBJECT
public:
    explicit ShowPic(QWidget *parent = 0);
    virtual ~ShowPic();

public:

signals:
private:
        QLabel *imageLabel;
        QFileInfoList m_fileInfoList;
        void resizeEvent(QResizeEvent *event);

public slots:
        void showPicture();

};

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

#if 1
class MyDialog:public QWidget, public Ui_Form 
{
    Q_OBJECT
    public:
        explicit MyDialog(QWidget *parent = 0);
        void changeRate(int value);
        void draw(QPainter *painter);
        void sendMsgTime(); 
    private slots:
        void enter();
        void recvMsg();
        void error();
    private:
        QString buf;
        int juge;
        /*QTcpSocket *tcpSocket;*/
        QString anotherstr;
        QLabel *background;
        QString msgBuffer;
        QTextBrowser *txtB;
};
#endif

class Frame : public QFrame
{
    Q_OBJECT
public:
    explicit Frame(QWidget *parent = 0);

    /*static QString strRoot;*/

    ShowVideo *video;
    ShowPic *pic;
    ShowText *text;
    ShowDate *showdate;
    ShowTime *showtime;
    MyDialog *d;

    void init();
    void stop();

signals:

public slots:

};

#endif

