#include <QtGui>
#include <iostream>
#include <fstream>
#include <QImage>
#include <QPixmap>
#include <QWidget>
#include <QMovie>
//#include <QHostAddress>
#include <QMessageBox>
#include <QByteArray>
#include <QDate>
#include <QDir>
#include <stdlib.h>
#include <QLabel>
#include <QVBoxLayout>
#include "mydialog.h"

#define SER_IP "10.1.14.30"

using namespace std;

int paint_pos;
int paint_txt_len;
int pic_no = 0;
int pic_num = 0;

#if 0
ShowVideo::ShowVideo(QWidget *parent) :
    QWidget(parent)
{
    // Video
    QString strPathVideo = "../MediaFile";
    this->mplayerProcess = new QProcess(this);
    render = new QWidget(this);
    render->move(0,0);
    //render->resize(543,355);
    render->setGeometry(5, 5, 545, 420);
    QStringList args;
    args << "-slave";
    args << "-quiet";
    args << "-wid"<<QString::number(render->winId());
    args << strPathVideo+"/paradise.flv";
    //args << strPath+"/akas.avi";
//    qDebug() << QDir::currentPath()+"/akas.avi";
    this->mplayerProcess->start("/usr/bin/mplayer", args);
}

ShowVideo::~ShowVideo()
{
    this->mplayerProcess->close();
}
#endif
#if 1
ShowText::ShowText(QWidget *parent) :
    QWidget(parent)
{
    //setGeometry(0, 0, 240,320);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslot()));
    char str[1024];
    memset(str, 0, 1024);
    ifstream infile("../TextFile/words.txt");
    for (int i = 0; i < 1024; i++) 
    {
        if (infile) 
        {
            infile.get(str[i]);
        }
        else
            break;
    }
    *(str + strlen(str)-1) = '\0';
    contentstr = QString::fromLocal8Bit(str);
    paint_txt_len = contentstr.length() *(fontMetrics().maxWidth());
    dirvalue = RTL;
    timer->start(300);
    //ShowText *text = new ShowText(this);
    //text->show();
}
ShowText::~ShowText() {}
#endif

MyDialog::MyDialog(QWidget *parent)
{
    parent = NULL;
    //setupUi(this);
    //cout << "MyDialog constor" << endl;
    //Qt::WindowFlags flags = 0;
    //flags |= Qt::FramelessWindowHint;

    //setFixedSize(800, 480);
    //resize(800, 480);

    QPalette plt = palette();
    plt.setColor(QPalette::Background, QColor(0x33, 0xff, 0x33, 255));
    setPalette(plt);
    setGeometry(0, 0, 800, 480);

    //CLOCK
    ymdlcd = new QLCDNumber(10, this);
    ymdlcd->setSegmentStyle(QLCDNumber::Filled);
    ymdlcd->setGeometry(QRect(425, 3, 505, 43));
    ymdlcd->setFrameShape(QFrame::NoFrame);
    QPalette plt2 = ymdlcd->palette();
    plt2.setColor(QPalette::Normal, QPalette::WindowText, Qt::black);
    ymdlcd->setPalette(plt2);

    lcd = new QLCDNumber(8, this);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setGeometry(QRect(436, 47, 466, 57));
    lcd->setFrameShape(QFrame::NoFrame);
    QPalette plt1 = lcd->palette();
    plt1.setColor(QPalette::Normal, QPalette::WindowText, Qt::black);
    lcd->setPalette(plt1);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(enter()));
    #if 0
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslot()));
    //connect(pushButton, SIGNAL(clicked()), this, SLOT(close()));
    //contentstr = QString::fromLocal8Bit("你好 !!!");
    char str[1024];
    memset(str, 0, 1024);
    ifstream infile("../TextFile/words.txt");
    for (int i = 0; i < 1024; i++) 
    {
        if (infile) 
        {
            infile.get(str[i]);
        }
        else
            break;
    }
    *(str + strlen(str)-1) = '\0';
    contentstr = QString::fromLocal8Bit(str);
    paint_txt_len = contentstr.length() *(fontMetrics().maxWidth());
    //cout << "len:" << paint_txt_len << endl;
    dirvalue = RTL;
    #endif

//show Picture
//QString strPath = Frame::strRoot +"../PictureFile";
    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    QString strPath = "../PictureFile";
    QDir dir(strPath);
    dir.setFilter(QDir::Files);
    m_fileInfoList = dir.entryInfoList();
    showPicture();
    QTimer* timerPic = new QTimer();
    timerPic->start(2000);
    connect(timerPic, SIGNAL(timeout()), this, SLOT(showPicture()));
    //imageLabel->setGeometry(QRect(556, 90, 796, 350));
    imageLabel->setGeometry(556,105,240,320);

    #if 1
    // Video
    QString strPathVideo = "../MediaFile";
    this->mplayerProcess = new QProcess(this);
    render = new QWidget(this);
    render->move(0,0);
    //render->resize(543,355);
    render->setGeometry(5, 5, 545, 420);
    QStringList args;
    args << "-slave";
    args << "-quiet";
    args << "-wid"<<QString::number(render->winId());
    args << strPathVideo+"/paradise.flv";
    //args << strPath+"/akas.avi";
//    qDebug() << QDir::currentPath()+"/akas.avi";
    this->mplayerProcess->start("/usr/bin/mplayer", args);
    #endif

    //TCPSOCKET
    #if 0
    tcpSocket = new QTcpSocket(this);
    connect(timerPic, SIGNAL(timeout()), this, SLOT(sendMsg()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(recvMsg()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));
    tcpSocket->connectToHost(QHostAddress("10.1.14.30"), 8000);
    #endif
    //time = QTime(12, 0);
    //time.start();
    sendMsgTime();
    timer->start(500);
}

void MyDialog::sendMsg()
{
    #if 0
    QTextStream out(tcpSocket);
    out << *picPath[pic_no % pic_num] + "|0|1" << endl;
    #endif
}

void MyDialog::sendMsgTime()
{
    #if 0
    QTextStream out(tcpSocket);
    out << "gettime" << endl;
    #endif
}

void MyDialog::recvMsg()
{
    #if 0
    QString t("date");
    //long It;
    if (!tcpSocket->canReadLine()) 
        return ;
    //do
    //responseLine += tcpSocket->readLine();
    //while(tcpSocket->canReadLine());
    msgBuffer = tcpSocket->readLine();
    //t = msgBuffer.toStdString();
    //cout << "recv:" << t << endl;
    //system(t.c_str());
    //It = msgBuffer.toLong(); 
    //printf("It:%ld\n",It);
    t += msgBuffer;
    QByteArray ba = t.toLatin1();
    const char *c_str2 = ba.data();
    printf("str2: %s", c_str2);
    system(c_str2);
    //stime(&It);
    //textBrowser->setText(msgBuffer);
    //textBrowser->moveCursor(QTextCursor::End);
    #endif
}

void MyDialog::error()
{
    #if 0
    QMessageBox::critical(this, "Socket error", tcpSocket->errorString());
    tcpSocket->close();
    #endif
}

void MyDialog::showTime()
{
    time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    lcd->display(text);
    QDate date = QDate::currentDate();
    QString date_text;
    date_text.sprintf("%d-%02d-%02d", date.year(), date.month(), date.day());
    ymdlcd->display(date_text);
}

void MyDialog::showPicture()
{
    if(m_fileInfoList.size() == 0)
        return;
    QFileInfo fileInfo = m_fileInfoList.at(0);
    QPixmap map(fileInfo.filePath());
    imageLabel->setPixmap(map);
    m_fileInfoList.removeFirst();
    m_fileInfoList.append(fileInfo);
}
#if 1
void ShowText::paintEvent(QPaintEvent *event)
{
    event = NULL;
    QPainter painter(this);
    painter.setFont(QFont("simsun", 22, QFont::Bold));
    painter.setPen(QColor(Qt::red));
    if (dirvalue == LTR) 
        painter.drawText(paint_pos, 420, contentstr);
    else if(dirvalue == RTL)
        //painter.drawText(width()-paint_pos, 460, contentstr);
        painter.drawText(width()-paint_pos, 140, contentstr);
    painter.end();
}

void ShowText::timeoutslot()
{
    static int ii = 0;
    #if 1
    int firstValue = fontMetrics().maxWidth();
    //cout << "firstvalue:" << firstValue << endl;
    paint_pos += firstValue;
    printf("%d\n",ii++);
    if (paint_pos > (width() + paint_txt_len)) 
    {
        paint_pos = 0;
    }
    update();
    //repaint(FALSE);
    #endif 
}
#endif

#if 0
void MyDialog::paintEvent(QPaintEvent *event)
{
    event = NULL;
    QPainter painter(this);
    painter.setFont(QFont("simsun", 22, QFont::Bold));
    painter.setPen(QColor(Qt::red));
    if (dirvalue == LTR) 
        painter.drawText(paint_pos, 420, contentstr);
    else if(dirvalue == RTL)
        painter.drawText(width()-paint_pos, 460, contentstr);
    painter.end();
}

void MyDialog::timeoutslot()
{
    #if 1
    int firstValue = fontMetrics().maxWidth();
    //cout << "firstvalue:" << firstValue << endl;
    paint_pos += firstValue;
    if (paint_pos > (width() + paint_txt_len)) 
    {
        paint_pos = 0;
    }
    update();
    //repaint(FALSE);
    #endif 
}
#endif

void MyDialog::resizeEvent(QResizeEvent *event)
{
    event = NULL;
    #if 0
    QRegion maskedRegion1(0, 0, width(), height());
    QRegion maskedRegion2(0, 0, 400, 300);
    setMask(maskedRegion1.subtracted(maskedRegion2));
    #endif
}

void MyDialog::enter()
{
    /*
    QTime time = QTime::currentTimeTime();
    QString text = "hello" + '\n';
    QString text = time.toString("hh:mm:ss.zzz");
    lineEdit->setText(text);
    timer->stop();
    */
}

//QString Frame::strRoot = "/sdcard";

Frame::Frame(QWidget *parent) :
    QFrame(parent)
{
    //resize(800, 480);
   // setWindowFlags(Qt::FramelessWindowHint);

   //setWindowTitle("My Ad Machine");
   /*
    QPalette plt = palette();
    plt.setColor(QPalette::Background, QColor(0x33, 0xff, 0x33, 255));
    setPalette(plt);
    setGeometry(0, 0, 800, 480);
    */

    setFixedSize(800, 480);
    init();
}

void Frame::init()
{
    //Qt::WindowFlags flags = 0;
    //flags |= Qt::FramelessWindowHint;

    d = new MyDialog(this);
    d->show();
    text = new ShowText(this);
    text->show();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(d,7);
    layout->addWidget(text,1);
    setLayout(layout);
}

void Frame::stop()
{
    delete this->d;
    delete this->text;
}

