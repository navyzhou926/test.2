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
#include <dirent.h>
#include "mydialog.h"

#define SER_IP "10.1.14.30"

using namespace std;

int paint_pos;
int paint_txt_len;

ShowVideo::ShowVideo(QWidget *parent) :
    QWidget(parent)
{
    DIR *dir;
    struct dirent *ptr;

    QString strPathVideo = "../MediaFile";
    this->mplayerProcess = new QProcess(this);
    render = new QWidget(this);
    render->move(0,0);
    render->resize(545,420);
    //render->setGeometry(5, 5, 545, 420);
    #if 1
    QStringList args;
    args << "-slave";
    args << "-quiet";
    args << "-loop";
    args << "-0";
    args << "-wid"<<QString::number(render->winId());
    if ((dir = opendir("../MediaFile")) != NULL) 
    {
        while ((ptr = readdir(dir)) != NULL)
        {
            if (ptr->d_type == DT_REG) 
            {
                //printf("%s\n",ptr->d_name);
                args << strPathVideo + "/" + ptr->d_name;
            }
        }
    }
    //args << strPath+"/akas.avi";
    //args << strPathVideo+"/I-believe.flv";
    this->mplayerProcess->start("/usr/bin/mplayer", args);
    #endif
    #if 0
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(lowerMute()));
    timer->start(2000);
    #endif
}

ShowVideo::~ShowVideo()
{
    this->mplayerProcess->close();
}

void ShowVideo::lowerMute()
{
    //process->write("pause\n");
    printf("hello\n");
    //system("echo \"pause\" > /tmp/cmd");
}

ShowDate::ShowDate(QWidget *parent) :
    QWidget(parent)
{
    ymdlcd = new QLCDNumber(10, this);
    ymdlcd->setFixedSize(QSize(200, 45));
    ymdlcd->setSegmentStyle(QLCDNumber::Filled);
    ymdlcd->setFrameShape(QFrame::NoFrame);
    ymdlcd->setSegmentStyle(QLCDNumber::Flat);	//FillBlack
    QPalette palette = this->palette();
    palette.setBrush(QPalette::WindowText, QBrush(QColor(255, 128, 0, 255)));			
    setPalette(palette);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showDate()));
    timer->start(300);
}
ShowDate::~ShowDate() {}

ShowTime::ShowTime(QWidget *parent) :
    QWidget(parent)
{
    lcd = new QLCDNumber(8, this);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setNumDigits (8);
    lcd->setFixedSize(QSize(214, 49));
    lcd->setFrameShape(QFrame::NoFrame);		//NoFrame
    lcd->setSegmentStyle(QLCDNumber::Flat);	//FillBlack
    QPalette palette = this->palette();
    palette.setBrush(QPalette::WindowText, QBrush(QColor(255, 128, 0, 255)));
    setPalette(palette);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(300);
}
ShowTime::~ShowTime() {}

ShowPic::ShowPic(QWidget *parent) :
    QWidget(parent)
{
    imageLabel = new QLabel(this);
    QString strPath = "../PictureFile";
    QDir dir(strPath);
    dir.setFilter(QDir::Files);
    m_fileInfoList = dir.entryInfoList();
    showPicture();
    QTimer* timerPic = new QTimer();
    timerPic->start(1200);
    connect(timerPic, SIGNAL(timeout()), this, SLOT(showPicture()));
}
ShowPic::~ShowPic() {}

ShowText::ShowText(QWidget *parent) :
    QWidget(parent)
{
    DIR *dir;
    struct dirent *ptr;
    char path[1024];
    char str[1024];
    memset(str, 0, 1024);
    int i = 0;
    //ifstream infile("../TextFile/words.txt");
    if ((dir = opendir("../TextFile")) != NULL) 
    {
        while ((ptr = readdir(dir)) != NULL)
        {
            if (ptr->d_type == DT_REG) 
            {
                printf("%s\n",ptr->d_name);
                if (strstr(ptr->d_name, ".txt")) 
                {
                    sprintf(path, "../TextFile/%s", ptr->d_name);
                    ifstream infile(path);
                    for (i = 0; i < 1024; i++) 
                    {
                        if (infile) 
                        {
                            infile.get(str[i]);
                        }
                        else
                            break;
                    }
                    for (i = 0; *(str + i) != '\0' ; i++) 
                    {
                        if (*(str + i) == '\n') 
                        {
                            *(str + i) = ' ';
                        }
                    }
                    //*(str + strlen(str)-1) = '\0';
                    contentstr = QString::fromLocal8Bit(str);
                    paint_txt_len = contentstr.length() *(fontMetrics().maxWidth());
                    dirvalue = RTL;
                    QTimer *timer = new QTimer;
                    timer->start(300);
                    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslot()));
                    break;
                }
            }
        }
    }
}
ShowText::~ShowText() {}

MyDialog::MyDialog(QWidget *parent)
{
    parent = NULL;
    //contentstr = QString::fromLocal8Bit("你好 !!!");
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
    //sendMsgTime();
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

void ShowTime::showTime()
{
    time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    lcd->display(text);
}

void ShowDate::showDate()
{
    QDate date = QDate::currentDate();
    QString date_text;
    date_text.sprintf("%d-%02d-%02d", date.year(), date.month(), date.day());
    ymdlcd->display(date_text);
}

void ShowPic::showPicture()
{
    if(m_fileInfoList.size() == 0)
        return;
    QFileInfo fileInfo = m_fileInfoList.at(0);
    QPixmap map(fileInfo.filePath());
    imageLabel->setPixmap(map);
    m_fileInfoList.removeFirst();
    m_fileInfoList.append(fileInfo);
}

void ShowText::paintEvent(QPaintEvent *event)
{
    event = NULL;
    QPainter painter(this);
    painter.setFont(QFont("simsun", 22, QFont::Bold));
    painter.setPen(QColor(Qt::red));
    if (dirvalue == LTR) 
        painter.drawText(paint_pos, 45, contentstr);
    else if(dirvalue == RTL)
        //painter.drawText(width()-paint_pos, 460, contentstr);
        painter.drawText(width()-paint_pos, 45, contentstr);
    painter.end();
}

void ShowText::timeoutslot()
{
    int firstValue = fontMetrics().maxWidth();
    //cout << "firstvalue:" << firstValue << endl;
    paint_pos += firstValue;
    if (paint_pos > (width() + paint_txt_len)) 
    {
        paint_pos = 0;
    }
    update();
    //repaint(FALSE);
}

void ShowPic::resizeEvent(QResizeEvent *event)
{
    imageLabel->setGeometry(0, 0, size().width(), size().height());
    imageLabel->setScaledContents(true);
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
   // setWindowFlags(Qt::FramelessWindowHint);

    setWindowTitle("Ad Machine");
    //resize(800, 480);
    setFixedSize(800, 480);
    //setFixedSize(1024, 768);
    init();
}

void Frame::init()
{
    #if 1
    QPalette plt = palette();
    plt.setColor(QPalette::Background, QColor(0x33, 0xff, 0x33, 255));
    setPalette(plt);
    setGeometry(0, 0, 800, 480);
    #endif
/*
    QString strPath = strRoot + "/adm/OtherFile/theme1.png";
    bkLabel = new QLabel(this);
    QPixmap background_pic(strPath);
    bkLabel->setPixmap(background_pic);
    bkLabel->show();
    bkLabel->setGeometry(0, 0, 800, 480);
    */

    //d = new MyDialog(this);
    //d->show();
    #if 1
    showdate= new ShowDate(this);
    showdate->setGeometry(575, 0, 225, 40);
    showdate->show();

    showtime = new ShowTime(this);
    showtime->setGeometry(568, 41, 232, 49);
    showtime->show();
    #endif

    pic = new ShowPic(this);
    pic->setGeometry(555, 90, 240, 320);
    pic->show();

    #if 1
    video = new ShowVideo(this);
    video->setGeometry(5, 5, 545, 420);
    video->show();

    text = new ShowText(this);
    text->setGeometry(5, 410,795,70);
    text->show();
    #endif
}

void Frame::stop()
{
    delete this->video;
    delete this->showdate;
    delete this->showtime;
    delete this->pic;
    delete this->text;
}

