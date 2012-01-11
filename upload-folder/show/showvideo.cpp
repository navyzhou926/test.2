#include "showvideo.h"
#include <QStringList>
#include <QDir>
#include <QDebug>
#include "frame.h"

#if 1
ShowVideo::ShowVideo(QWidget *parent) :
    QWidget(parent)
{
    //QString strPath = Frame::strRoot +"/../MediaFile";
    QString strPath = "../MediaFile";
    this->mplayerProcess = new QProcess(this);
    render = new QWidget(this);
    render->move(0,0);
    render->resize(543,355);
    QStringList args;
    args << "-slave";
    args << "-quiet";
    args << "-wid"<<QString::number(render->winId());
    args << strPath+"/paradise.flv";
    //args << strPath+"/akas.avi";
//    qDebug() << QDir::currentPath()+"/akas.avi";
    this->mplayerProcess->start("/usr/bin/mplayer", args);
}

ShowVideo::~ShowVideo()
{
    this->mplayerProcess->close();
}
#endif

