#include "showlogo.h"
#include <QMovie>
#include "frame.h"
ShowLogo::ShowLogo(QWidget *parent) :
    QLabel(parent)
{
    QString strPath = Frame::strRoot + "/adm/OtherFile/logo.gif";
    QMovie* movie = new QMovie(strPath);
    movie->setScaledSize(QSize(80, 60));
    setMovie(movie);
    movie->setSpeed(70);  //设置logo的播放速度
    movie->start();
}
