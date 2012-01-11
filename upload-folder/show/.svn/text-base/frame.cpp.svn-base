#include "frame.h"
#include "showvideo.h"
#include "showpic.h"
#include "showlogo.h"
#include "showtext.h"
#include "showclock.h"

QString Frame::strRoot = "/sdcard";

Frame::Frame(QWidget *parent) :
    QFrame(parent)
{
    resize(800, 480);
   // setWindowFlags(Qt::FramelessWindowHint);

    setWindowTitle("My Ad Machine");

    init();
}

void Frame::init()
{
    QString strPath = strRoot + "/adm/OtherFile/theme1.png";
    bkLabel = new QLabel(this);
    QPixmap background_pic(strPath);
    bkLabel->setPixmap(background_pic);
    bkLabel->show();
    bkLabel->setGeometry(0, 0, 800, 480);

    sv = new ShowVideo(this);
    sv->setGeometry(23, 18, 543, 355);
    sv->show();

    sp = new ShowPic(this);
    sp->setGeometry(586,127,190,246);
    sp->show();

    sl = new ShowLogo(this);
    sl->setGeometry(652,18,105,94);
    sl->show();

    sc = new ShowClock(this);
    sc->setGeometry(592,18,185,92);
    sc->show();

    st = new ShowText(this);
    st->setGeometry(23,396,754,69);
    st->show();
}

void Frame::stop()
{
    delete this->bkLabel;
    delete this->sv;
    delete this->sp;
    delete this->sl;
    delete this->sc;
    delete this->st;
}
